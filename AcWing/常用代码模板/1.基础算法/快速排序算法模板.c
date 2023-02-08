void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;//if (l == r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];//等同于x = q[(l + r + 1) / 2] 注意边界问题：左i不能取左l，右j不能取右r
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);//quick_sort(q, l, i-1)
    quick_sort(q, j + 1, r);//quick_sort(q, i, r)
}
void quick_sort(int a[], int l, int r) {
    if (l >= r) return ;

    int x = a[l + r >> 1], i = l, j = r;

    while (i <= j) {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }

    quick_sort(a, l, j);
    quick_sort(a, i, r);
}