/* ============================================================
   cin_get_demo.cpp —— cin >> / cin.get() / cin.getline() 三兄弟的区别
   注释即讲义。运行方式（它是交互程序，要你敲键盘）：
     g++ -std=c++17 -g cin_get_demo.cpp -o cin_get_demo && ./cin_get_demo
   ============================================================ */

#include <iostream>
#include <cstring>    // strlen 在这里（C 的 string.h 对应 C++ 的 cstring）
using namespace std;

int main()
{
    /* ================= 第 1 幕：>> 读完数字，回车赖在队列里 ================= */

    int year;
    char addr[80];

    cout << "请输入年份（比如 2026）然后回车: ";
    cin >> year;              // 只读数字，回车 '\n' 留在输入队列里没被带走

    cout << "请输入地址（不用输，直接看程序干了什么）: ";
    cin.get(addr, 80);        // ⚠️ 一上来就撞见那个回车 → 立刻结束，addr 是空串！

    cout << "  year = " << year << '\n';
    cout << "  addr = [" << addr << "]  长度 = " << strlen(addr) << '\n';
    // 预期：addr 是空的（长度 0）。这就是 C++ 输入最经典的 bug。

    /* ================= 第 2 幕：加一个 .get() 吃掉回车 ================= */

    char addr2[80];
    cout << "请输入一句带空格的话（比如 Shanghai Jiao Tong University）: ";
    (cin >> year).get();      // ★ 链式写法：读完数字后，再读走那个回车
    // 等价于两句：cin >> year;  cin.get();
    cin.get(addr2, 80);       // 现在能正常读到一行了

    cout << "  addr2 = [" << addr2 << "]\n";

    /* ================= 第 3 幕：get 与 getline 的唯一区别 ================= */

    char x[80], y[80];
    cout << "输入第一行: ";
    (cin >> year).get();
    cin.get(x, 80);           // get：遇到换行停下，换行符【留在队列】
    cin.get();                // 手动把那个换行吃掉
    cout << "输入第二行: ";
    cin.get(y, 80);

    cout << "  x = [" << x << "]  y = [" << y << "]\n";

    char p[80], q[80];
    cout << "输入第三行: ";
    (cin >> year).get();
    cin.getline(p, 80);       // getline：遇到换行停下，并且【把换行吃掉丢掉】
    cout << "输入第四行: ";
    cin.getline(q, 80);       // 不需要中间再插 cin.get() ← 这就是唯一区别

    cout << "  p = [" << p << "]  q = [" << q << "]\n";

    /* ================= 第 4 幕：第二个参数 n 到底能读几个字符 ================= */

    char small[5];
    cout << "输入一长串（比如 abcdefghij，看它只收几个）: ";
    (cin >> year).get();
    cin.get(small, 5);        // 数组 5 字节 → 最多读【4】个字符，第 5 格留给 '\0'
    cout << "  small = [" << small << "]  长度 = " << strlen(small) << '\n';
    // 输入 abcdefghij → 只收到 abcd（4 个），剩下的 efghij 还留在队列里！

    return 0;
}

/* ============================================================
   三兄弟速查表（抄在书的第一页）

   cin >> x          读一个"词"，跳过前导空格，遇到空格/换行停，
                     【把分隔符留在队列里】。不能读含空格的一整行。

   cin.get(ch)       读【一个字符】，空格和换行也照读不误。
                     常用来"吃掉"前面残留的换行。

   cin.get(arr, n)   读【一行】，最多 n-1 个字符，
                     遇到换行停，【换行符留在队列】。

   cin.getline(arr,n) 读【一行】，最多 n-1 个字符，
                     遇到换行停，【换行符吃掉并丢掉】。

   ★ 记住：get 留垃圾，getline 清垃圾。
   ★ 记住：n 是数组总大小，实际能读 n-1 个字符，最后一格必须留给 '\0'。
   ★ 记住：混用 >> 和 get/getline 时，中间必须插一次 cin.get() 或 (cin>>x).get()。
   ============================================================ */
