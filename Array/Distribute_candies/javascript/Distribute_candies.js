function candiesDistribute(array,n){
	var candies = new Set();
	array.map(v => candies.add(v));
	return Math.min(candies.size,n/2);
}
console.log(candiesDistribute(process.argv.slice(2),process.argv.slice(2).length))
