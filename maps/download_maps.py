from pprint import pprint
from typing import List
from glob import glob
from tqdm import tqdm
from bs4 import BeautifulSoup
import requests
import os
import subprocess

# thanks abarrier for the maps

REPO_URL = "https://github.com/Alicia-bites/cub3d/tree/abarrier/maps"
OK_PREFIXES = ["ko", "ok"] # download only maps that starts with ko or ok
already_downloaded = glob("*.cub")

def get_maps(already_downloaded: List[str]):
	r = requests.get(REPO_URL)
	soup = BeautifulSoup(r.text, "html.parser")
	maps = [a["href"] for a in soup.find_all("a") if a["href"].endswith(".cub")]
	maps = [m for m in maps if m.split("/")[-1] not in already_downloaded]
	maps = [m for m in maps if m.split("/")[-1].split(".")[0].split("_")[0] in OK_PREFIXES]
	names = [m.split("/")[-1] for m in maps]
	maps = [f"https://raw.githubusercontent.com/Alicia-bites/cub3d/abarrier/maps/{n}" for n in names]
	return maps

to_download = get_maps(already_downloaded)

if len(to_download) == 0:
	print("🎉  No new maps to download !")
else:
	print(f"📥 Downloading {len(to_download)} maps...")

	for url in tqdm(to_download, desc="Downloading maps", unit="map"):
		r = requests.get(url, stream=True)
		output_path = os.path.join(".", url.split("/")[-1])
		with open(output_path, "wb+") as output_file:
			for chunk in r.iter_content(chunk_size=4096):
				if chunk:
					output_file.write(chunk)

try:
	current_branch = subprocess.check_output(["git", "rev-parse", "--abbrev-ref", "HEAD"]).decode("utf-8").strip()
except:
	print("❌  Error while getting current branch")
	exit(1)

if current_branch == "master" or current_branch == "main":
	print("💙 Avoiding unsafe push to branch", current_branch)
	exit(0)

# Push changes to github
print("📤 Pushing changes to GitHub -- branch {}".format(current_branch))
subprocess.run(["git", "add", "*.cub"])
subprocess.run(["git", "commit", "-m", "update: updated map folder (automatic push)"])
subprocess.run(["git", "push"])