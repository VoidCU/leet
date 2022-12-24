#include <iostream>
#include <vector>
using namespace std;

vector<float> operator-(vector<float> a, vector<float> b)
{
    if (a.size() != b.size())
    {
        cout << " not same size" << endl;
        exit(0);
    }
    for (int i = 0; i < a.size(); i++)
    {
        a[i] -= b[i];
    }
    return a;
}

vector<float> operator+(vector<float> a, vector<float> b)
{
    if (a.size() != b.size())
    {
        cout << " not same size" << endl;
        exit(0);
    }
    for (int i = 0; i < a.size(); i++)
    {
        a[i] += b[i];
    }
    return a;
}

vector<float> operator*(vector<float> a, float b)
{

    for (int i = 0; i < a.size(); i++)
    {
        a[i] *= b;
    }
    return a;
}

vector<float> operator/(vector<float> a, float b)
{

    for (int i = 0; i < a.size(); i++)
    {
        a[i] /= b;
    }
    return a;
}

vector<float> cross(vector<float> point1, vector<float> point2)
{
    return {(point1[1] * point2[2]) - (point2[1] * point1[2]), -(point1[0] * point2[2]) + (point2[0] * point1[2]), (point1[0] * point2[1]) - (point2[0] * point1[1])};
}

float dot(vector<float> point1, vector<float> point2)
{
    return point1[0] * point2[0] + point1[1] * point2[1] + point1[2] * point2[2];
}
void dis(vector<float> a)
{
    cout << "{";
    for (int i = 0; i < a.size(); i++)
    {
        if (i != a.size() - 1)
            cout << a[i] << ",";
        else
            cout << a[i] << "}" << endl;
    }
}

vector<float> intersectPoint(vector<vector<float>> line1, vector<vector<float>> line2)
{
    vector<float> fline1 = line1[0] - line1[1];
    vector<float> fline2 = line2[0] - line2[1];

    vector<float> perp = cross(fline1, fline2);
    perp = cross(fline1, perp);
    float u = dot(perp, line1[1]);
    float t = (u - dot(perp, line2[1])) / dot(perp, fline2);
    return line2[1] + (fline2 * t);
}
vector<float> eqofplain(vector<float> p1, vector<float> p2, vector<float> p3)
{
    p2 = p2 - p1;
    p3 = p3 - p1;
    p2 = cross(p2, p3);
    float d = -p2[0] * p1[0] - p2[1] * p1[1] - p2[2] * p1[2];
    return {p2[0], p2[1], p2[2], d};
}

int main()
{
    vector<vector<vector<float>>> lines;
    vector<float> ip1a, ip1b, ip2a, ip2b, ip3a, ip3b;

    // 2lines ,1st intersection
    lines = {{{10, 10, 6}, {6, 6, 6}}, {{4, 10, 2}, {5, 5, 2}}};
    ip1a = intersectPoint(lines[0], lines[1]);
    ip1b = intersectPoint(lines[1], lines[0]);
    dis(ip1a);
    dis(ip1b);
    ip1a = ip1a + ip1b;
    ip1a = ip1a / 2;

    // 2lines ,2nd intersection
    lines = {{{5, 2, -1}, {6, 0, -4}}, {{2, 0, 4}, {3, 2, 3}}};
    ip2a = intersectPoint(lines[0], lines[1]);
    ip2b = intersectPoint(lines[1], lines[0]);
    ip2a = ip2a + ip2b;
    ip2a = ip2a / 2;

    // 2lines ,3rd intersection
    lines = {{{12, 15, 4}, {6, 8, 4}}, {{12, 15, 6}, {6, 8, 2}}};
    ip3a = intersectPoint(lines[0], lines[1]);
    ip3b = intersectPoint(lines[0], lines[1]);
    ip3a = ip3a + ip3b;
    ip3a = ip3a / 2;

    dis(ip1a);
    dis(ip2a);
    dis(ip3a);

    vector<float> eq;
    eq = eqofplain(ip1a, ip2a, ip3a);
    dis(eq);
    return 0;
}
