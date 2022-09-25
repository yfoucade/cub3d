import subprocess
import argparse
from glob import glob

args = argparse.ArgumentParser()
args.add_argument('-q', '--quiet', action='store_true', help='Suppress succeeded tests')
args = args.parse_args()

maps = glob("maps/*")
maps = [m for m in maps if not m.endswith(".py")]

for map in maps:
	expected = map.split('/')[-1].split("_")[0] == "ko"
	got = 0
	try:
		subprocess.check_call(["./parsing_check", map], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
		got = 0
	except:
		got = 1
	if expected != got:
		print("Test failed", map, "❌")
	if expected == got and not args.quiet:
		print("Tested successfully", map, "✅")