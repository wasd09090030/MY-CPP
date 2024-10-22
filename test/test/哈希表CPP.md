
//头文件
#include<unordered_map>


//声明：
unordered_map<elemType_1, elemType_2> var_name; //声明一个没有任何元素的哈希表，
//其中elemType_1和elemType_2是模板允许定义的类型，如要定义一个键值对都为Int的哈希表：
unordered_map<int, int> map;


//初始化
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
//如果知道要创建的哈希表的元素个数时，也可以在初始化列表中指定元素个数
unordered_map<int, int> hmap{ {{1,10},{2,12},{3,13}},3 };



//添加元素
//当我们想向哈希表中添加元素时也可以直接通过下标运算符添加元素，格式为: mapName[key]=value;
//如：hmap[4] = 14;
//但是这样的添加元素的方式会产生覆盖的问题，也就是当hmap中key为4的存储位置有值时，
//再用hmap[4]=value添加元素，会将原哈希表中key为4存储的元素覆盖
hmap[4] = 14;
hmap[5] = 15;
cout << hmap[4];  //结果为15

//通过insert()函数来添加元素的结果和通过下标来添加元素的结果一样，不同的是insert()可以避免覆盖问题，
//insert()函数在同一个key中插入两次，第二次插入会失败
hmap.insert({ 5,15 });
hmap.insert({ 5,16 });
cout << hmap[5];  //结果为15

//可以复制其他已经初始化的哈希表
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
unordered_map<int, int> hmap1(hmap);


//常见函数

begin() //指向哈希表的第一个容器 也就是{1，10}
end()  //指向哈希表的最后一个容器，实则超出了哈希表的范围，为空

at()函数：根据key查找哈希表中的元素
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
int elem = hmap.at(3);

erase()函数： 删除某个位置的元素，或者删除某个位置开始到某个位置结束这一范围内的元素， 或者传入key值删除键值对
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
unordered_map<int, int>::iterator iter_begin = hmap.begin();
unordered_map<int, int>::iterator iter_end = hmap.end();
hmap.erase(iter_begin);  //删除开始位置的元素
hmap.erase(iter_begin, iter_end); //删除开始位置和结束位置之间的元素
hmap.erase(3); //删除key==3的键值对

clear()函数：清空哈希表中的元素

find()函数
hamp.find(2)查找key为2的键值对是否存在 ,若没找到则返回hamp.end()
if(hamp.find(2)!=hamp.end()) //判断找到了key为2的键值对

遍历：
unordered_map<int, int> count;
for (auto p : count) {
	int front = p.first;   //key
    int end = p.second;   //value
}






