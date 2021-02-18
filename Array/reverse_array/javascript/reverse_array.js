function reversed(arr){
	return [...arr].reverse().join(" ")
}
console.log(reversed(process.argv.slice(2)));

//In javascript process.argv gives the array ["node","reverse_array.js","1","2"..]
