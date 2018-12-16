EnterBox有两个构造函数，分别对应边界上的EnterBox和内部的EnterBox
点击EnterBox实现将SquareUnit的度（deg）减一并且activation（问题可能出在这里）

activation（）
{
	switch
	{
	case：度为0
		变颜色
	case：度不为0
		让Squares去变所有SquareUnit的Player
	}
}
