
//ͷ�ļ�
#include<unordered_map>


//������
unordered_map<elemType_1, elemType_2> var_name; //����һ��û���κ�Ԫ�صĹ�ϣ��
//����elemType_1��elemType_2��ģ������������ͣ���Ҫ����һ����ֵ�Զ�ΪInt�Ĺ�ϣ��
unordered_map<int, int> map;


//��ʼ��
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
//���֪��Ҫ�����Ĺ�ϣ���Ԫ�ظ���ʱ��Ҳ�����ڳ�ʼ���б���ָ��Ԫ�ظ���
unordered_map<int, int> hmap{ {{1,10},{2,12},{3,13}},3 };



//���Ԫ��
//�����������ϣ�������Ԫ��ʱҲ����ֱ��ͨ���±���������Ԫ�أ���ʽΪ: mapName[key]=value;
//�磺hmap[4] = 14;
//�������������Ԫ�صķ�ʽ��������ǵ����⣬Ҳ���ǵ�hmap��keyΪ4�Ĵ洢λ����ֵʱ��
//����hmap[4]=value���Ԫ�أ��Ὣԭ��ϣ����keyΪ4�洢��Ԫ�ظ���
hmap[4] = 14;
hmap[5] = 15;
cout << hmap[4];  //���Ϊ15

//ͨ��insert()���������Ԫ�صĽ����ͨ���±������Ԫ�صĽ��һ������ͬ����insert()���Ա��⸲�����⣬
//insert()������ͬһ��key�в������Σ��ڶ��β����ʧ��
hmap.insert({ 5,15 });
hmap.insert({ 5,16 });
cout << hmap[5];  //���Ϊ15

//���Ը��������Ѿ���ʼ���Ĺ�ϣ��
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
unordered_map<int, int> hmap1(hmap);


//��������

begin() //ָ���ϣ��ĵ�һ������ Ҳ����{1��10}
end()  //ָ���ϣ������һ��������ʵ�򳬳��˹�ϣ��ķ�Χ��Ϊ��

at()����������key���ҹ�ϣ���е�Ԫ��
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
int elem = hmap.at(3);

erase()������ ɾ��ĳ��λ�õ�Ԫ�أ�����ɾ��ĳ��λ�ÿ�ʼ��ĳ��λ�ý�����һ��Χ�ڵ�Ԫ�أ� ���ߴ���keyֵɾ����ֵ��
unordered_map<int, int> hmap{ {1,10},{2,12},{3,13} };
unordered_map<int, int>::iterator iter_begin = hmap.begin();
unordered_map<int, int>::iterator iter_end = hmap.end();
hmap.erase(iter_begin);  //ɾ����ʼλ�õ�Ԫ��
hmap.erase(iter_begin, iter_end); //ɾ����ʼλ�úͽ���λ��֮���Ԫ��
hmap.erase(3); //ɾ��key==3�ļ�ֵ��

clear()��������չ�ϣ���е�Ԫ��

find()����
hamp.find(2)����keyΪ2�ļ�ֵ���Ƿ���� ,��û�ҵ��򷵻�hamp.end()
if(hamp.find(2)!=hamp.end()) //�ж��ҵ���keyΪ2�ļ�ֵ��

������
unordered_map<int, int> count;
for (auto p : count) {
	int front = p.first;   //key
    int end = p.second;   //value
}






