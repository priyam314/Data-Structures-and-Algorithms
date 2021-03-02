object candy {
	def main(args:Array[String]){
		println(candiesDistribute(args,args.length))
	}
	def candiesDistribute(candyType:Array[String],n:Int):Int={
		return ((candyType.toSet).size).min(n/2)
	}		
}
object candies {
	def main(args:Array[String]){
		println((args.length/2).min(args.toSet.size))
	}
}

//scala candies 6 6 6 6
//scala candy 6 6 6 6
