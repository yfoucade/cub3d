import subprocess
import argparse
from glob import glob
from typing import List

args = argparse.ArgumentParser()
args.add_argument('-l', '--leaks', action='store_true', help='Test for leaks')
args.add_argument('-e', '--errors', action='store_true', help='Test for memory errors')
args.add_argument("-a", '--all', action='store_true', help='Test for everything')
args = args.parse_args()

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

for map in maps:
	expected = map.split('/')[-1].split("_")[0] == "ko"
	try:
		subprocess.check_call(["./parsing_check", map], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
		got = 0
	except:
		got = 1
	if args.leaks or args.all:
		leaks = check_leaks(["./parsing_check", map])
	else:
		leaks = False
	if args.errors or args.all:
		memory_error = check_memory_errors(["./parsing_check", map])
	else:
		memory_error = False
	print("Map : {}".format(map), end=" ")
	if memory_error:
		print("🐛")
	if leaks:
		print("🚰")
	if expected != got:
		print("❌")
	else:
		print("✅")