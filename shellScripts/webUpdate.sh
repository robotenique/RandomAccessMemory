#!/bin/bash
# Usage:
#   ./webUpdate.sh

function updt {
	dir="./"
	repo_url="https://github.com/robotenique/roboteniqueWeb"
	repo_name="roboteniqueWeb/"
	echo "****************************************************************************"
	echo "Updating Repo $repo_name with url: $repo_url"
	echo "Starting update..."

	main_branch="master"
	if [ "$repo_url" == "git@someserver:repo/repo.git" ]; then # if you have a repo where the primary branch isnt master
	    $main_branch="trunk"
	fi

	# update the repo, then stash any local changes
	echo -e "\ncalling: git clone (roboteniqueWeb)"
	(git clone $repo_url)
	echo -e "\nremoving: .git and .gitignore"
	(rm -rf roboteniqueWeb/.g*)
	(tar -cvzpf tmp.tar.gz roboteniqueWeb/*)
	(mv roboteniqueWeb/tmp.tar.gz ./tmp.tar.gz)
	(rm -rf roboteniqueWeb/*)
	(rmdir roboteniqueWeb)
	echo -e "\nRemoving old files..."
	(ls | egrep -v "(tmp.tar.gz|webUpdate.sh)+" | xargs rm -rf)
	echo -e "\nExtracting new files..."
	(tar -xvzpf tmp.tar.gz --strip-components 1)
	(rm tmp.tar.gz)
	echo "$repo_name have been updated!"
}
#FKING SHELL
# TO DECLARE A VARIABLE: MUST NOT USE SPACE
# TO USE SQUARE BRACKETS IN IF: MUST DEFINITELY USE SPACE
# OUT!
var=1
var2=42

if [ "$var" -eq $# ]; then
	if [ $1 -eq 42 ]; then
		updt
	else
		echo "ERROR! TRY AGAIN"
	fi
fi
exit 0
