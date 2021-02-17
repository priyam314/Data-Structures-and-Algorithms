def reversed(a:Array[String]):String{
	return a.reverse().mkString(" ")
}
object Reverse{
	def main(args:Array[String]){
		println(reversed(args))
	}
}


