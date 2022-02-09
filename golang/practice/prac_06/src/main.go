package main

import "fmt"

/*
var vInt int

func main() {
	fmt.Println(vInt)
	var vInt int = 3
	fmt.Println(reflect.TypeOf(vInt))
	if vInt := 1; vInt < 2 {
		fmt.Println(vInt)
	}
	fmt.Println(vInt)
	func1()
}
func func1() {
	fmt.Println(vInt)
}*/

//初始暴击5%，初始爆伤50%
/**
1.圣遗物词条：1%暴击==1分 2%爆伤==1分
2.计算期望伤害,假设攻击力为1000
*/
func main() {
	//分数递增

	for score := 0; score <= 300; score++ {
		var maxW float64
		var maxBaoji float64
		var maxBaoshang float64
		fmt.Print("总分数:", score, "\n")
		for baoji := 0; baoji < score; baoji++ {
			baoshang := float64(score-baoji) * 2.0
			//计算伤害期望
			zongbaojilv := float64(baoji)/100.0 + 0.05
			if zongbaojilv > 1.0 {
				break
			}
			zongbaoshang := 1.0 + 0.5 + float64(baoshang)
			w := 1000 * (1.0 + zongbaoshang*zongbaojilv)
			//fmt.Print("\t暴击率：", zongbaojilv, "\t爆伤：", zongbaoshang, "\t伤害期望：", w, "\t\t")
			if w > maxW {
				maxBaoji = zongbaojilv
				maxBaoshang = zongbaoshang
				maxW = w
			}
		}
		//最高伤害期望
		fmt.Println("总分数", score, "下最高伤害期望", maxW, "\t暴击率", maxBaoji, "\t爆伤", maxBaoshang)

	}

}
