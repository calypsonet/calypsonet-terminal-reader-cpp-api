#!/bin/sh

echo "Compute the current API version..."

version=$1

if [ "$version" = "" ]
then
  version_major="`cat CMakeLists.txt | grep -P 'CMAKE_PROJECT_VERSION_MAJOR.*\"([0-9]*)\"' -o`
  version_minor="`cat CMakeLists.txt | grep -P 'CMAKE_PROJECT_VERSION_MINOR.*\"([0-9]*)\"' -o`
  version_patch="`cat CMakeLists.txt | grep -P 'CMAKE_PROJECT_VERSION_PATCH.*\"([0-9]*)\"' -o`
  version="${version_major}.${version_minor}.${version_patch}"
fi

echo "Computed current API version: $version"

repository_name=`git rev-parse --show-toplevel | xargs basename`

echo "Clone $repository_name..."
git clone https://github.com/calypsonet/$repository_name.git

cd $repository_name

echo "Checkout gh-pages branch..."
git checkout -f gh-pages

echo "Delete existing SNAPSHOT directory..."
rm -rf *-SNAPSHOT

echo "Create target directory $version..."
mkdir $version

echo "Copy Doxygen doc..."
cp -rf ../html/* $version/

echo "Update versions list..."
echo "| Version | Documents |" > list_versions.md
echo "|:---:|---|" >> list_versions.md
for directory in `ls -rd [0-9]*/ | cut -f1 -d'/'`
do
  echo "| $directory | [API documentation]($directory) |" >> list_versions.md
done

echo "Computed all versions:"
cat list_versions.md

cd ..

echo "Local docs update finished."



