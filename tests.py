import subprocess
import argparse
from glob import glob
from time import time, time_ns
from typing import List
from colorama import Fore, Style, Back

args = argparse.ArgumentParser()
args.add_argument('-l', '--leaks', action='store_true', help='Test for leaks')
args.add_argument('-e', '--errors', action='store_true', help='Test for memory errors')
args.add_argument("-a", '--all', action='store_true', help='Test for everything')
args = args.parse_args()

KEEP_SUCCESSES = False

maps = glob("maps/*")
maps = [m for m in maps if not m.endswith(".py")]

def check_leaks(args: List[str]) -> bool:
	"""
	Run parser using Valgrind and check for memory leaks
	"""
	proc = subprocess.Popen(["valgrind", "--leak-check=full"] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	_, err = proc.communicate()
	return b"All heap blocks were freed -- no leaks are possible" not in err

def check_memory_errors(args: List[str]) -> bool:
	"""
	Run parser using Valgrind and check for memory errors
	"""
	proc = subprocess.Popen(["valgrind"] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	_, err = proc.communicate()
	return b"ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" not in err


success, fails, total_leaks, total_memory_error = 0, 0, 0, 0
times = []
for i, map in enumerate(maps):
	expected = map.split('/')[-1].split("_")[0] == "ko"
	start = time_ns()
	proc = subprocess.Popen(["./parsing_check", map], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	out, err = proc.communicate()
	end = time_ns()
	times.append(end - start)
	got = proc.returncode != 0
	if args.leaks or args.all:
		leaks = check_leaks(["./parsing_check", map])
	else:
		leaks = False
	if args.errors or args.all:
		memory_error = check_memory_errors(["./parsing_check", map])
	else:
		memory_error = False
	if expected == got and not leaks and not memory_error and not KEEP_SUCCESSES:
		continue
	if i > 0:
		print("\n" + Style.BRIGHT + Fore.LIGHTYELLOW_EX + "-"*80 + Style.RESET_ALL + "\n")
	print(Fore.LIGHTMAGENTA_EX + "Map : {}".format(map) + Style.RESET_ALL, end=" ")
	if memory_error:
		print("🐛", end=" ")
		total_memory_error += 1
	if leaks:
		print("🚰", end=" ")
		total_leaks += 1
	if expected != got:
		print("❌", end=" ")
		fails += 1
	else:
		print("✅", end=" ")
		success += 1
	print(Fore.LIGHTBLUE_EX + "({:.2f}ms)".format((end - start) / 1000000) + Style.RESET_ALL)
	combined_output = (out.decode("utf-8") + err.decode("utf-8")).strip()
	if len(combined_output) > 0:
		print(combined_output)
	else:
		print(Fore.LIGHTRED_EX + "No output" + Style.RESET_ALL)

print(Fore.LIGHTYELLOW_EX + "\n" + "-"*80 + "\n" + Style.RESET_ALL)
print(Fore.LIGHTGREEN_EX + "✅ Success : {}".format(success) + Style.RESET_ALL)
print(Fore.LIGHTRED_EX + "❌ Fails : {}".format(fails))
print("🚰 Leaks : {}".format(total_leaks))
print("🐛 Memory errors : {}".format(total_memory_error) + Style.RESET_ALL)
print(Fore.LIGHTMAGENTA_EX + "📊 Total : {}".format(success + fails + leaks + memory_error) + Style.RESET_ALL)

print(Fore.LIGHTBLUE_EX + "🕒 Average time : {:.2f}ms".format(sum(times) / len(times) / 1000000) + Style.RESET_ALL)