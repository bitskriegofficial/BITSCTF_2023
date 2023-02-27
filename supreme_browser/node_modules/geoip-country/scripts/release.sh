# get current version from package.json
VER=`node -p "require('./package.json').version"`

git config --local user.email "action@github.com"
git config --local user.name "GitHub Action"
git commit -a -m "Auto Release v${VER} for updating ip data"
