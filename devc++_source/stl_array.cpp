#include <iostream>
//��Ҫ���� array ͷ�ļ�
#include <array>
using namespace std;

//int main()
//{
//	array<int,5>values;
//	int h =1;
//	auto frist =values.begin();
//	auto last =values.end();
//	while(frist != last)
//	{
//		*frist=h;
//		h++;
//		frist++;
//	}
//	frist = values.begin();
//	while(frist!=last)
//	{
//		cout<<*frist<<endl;
//		frist++;
//	}
//	return 0;
//}
//int main()
//{
//    std::array<int, 4> values{};
//    //��ʼ�� values ����Ϊ {0,1,2,3}
//    for (int i = 0; i < values.size(); i++) {
//        values.at(i) = i;
//    }
//    //ʹ�� get() ���غ������ָ��λ��Ԫ��
//    cout << get<3>(values) << endl;
//    //���������Ϊ�գ���������������е�Ԫ��
//    if (!values.empty()) {
//        for (auto val = values.begin(); val < values.end(); val++) {
//            cout << *val << " ";
//        }
//    }
//}
