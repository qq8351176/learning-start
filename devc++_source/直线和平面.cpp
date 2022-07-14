/// <summary>
/// 求一条直线与平面的交点
/// </summary>
/// <param name="planeVector">平面的法线向量，长度为3</param>
/// <param name="planePoint">平面经过的一点坐标，长度为3</param>
/// <param name="lineVector">直线的方向向量，长度为3</param>
/// <param name="linePoint">直线经过的一点坐标，长度为3</param>
/// <returns>返回交点坐标，长度为3</returns>
private float[] CalPlaneLineIntersectPoint(float[] planeVector, float[] planePoint, float[] lineVector, float[] linePoint)
{
float[] returnResult = new float[3];
float vp1, vp2, vp3, n1, n2, n3, v1, v2, v3, m1, m2, m3, t,vpt;
vp1 = planeVector[0];
vp2 = planeVector[1];
vp3 = planeVector[2];
n1 = planePoint[0];
n2 = planePoint[1];
n3 = planePoint[2];
v1 = lineVector[0];
v2 = lineVector[1];
v3 = lineVector[2];
m1 = linePoint[0];
m2 = linePoint[1];
m3 = linePoint[2];
vpt = v1 * vp1 + v2 * vp2 + v3 * vp3;
//首先判断直线是否与平面平行
if (vpt == 0)
{
returnResult = null;
}
else
{
t = ((n1 - m1) * vp1 + (n2 - m2) * vp2 + (n3 - m3) * vp3) / vpt;
returnResult[0] = m1 + v1 * t;
returnResult[1] = m2 + v2 * t;
returnResult[2] = m3 + v3 * t;
}
return returnResult;
}
