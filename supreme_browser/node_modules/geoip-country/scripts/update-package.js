
const fs = require('fs')

var stat1 = fs.statSync('data/geoip-country.dat')
var stat2 = fs.statSync('data/geoip-country6.dat')
if(stat1.size > 1024 * 1024 && stat2.size > 2 * 1024 * 1024){
	var json = JSON.parse(fs.readFileSync('package.json', 'utf8'))
	json.version = json.version.replace(/(\d+)$/, function(r){return (r|0)+1})
	fs.writeFileSync('package.json', JSON.stringify(json, null, "\t"))
}
