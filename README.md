# Connie

C言語用単体テストF/W

## クイックスタート

```c
#include <connie_sugar.h>

// テスト関数
void do_test(c *connie_Connie);
// TODO テスト関数を追加する場合は、ここにプロトタイプ宣言を追加する。

int main(void)
{
    connie_Connie *c = connie_new(__FILE__);

    TEST(c, "do_test", do_test);
    // TODO テスト関数を追加した場合は、ここにTEST()による呼び出し処理を追加する。

    connie_print(c);
    connie_delete(c);

    return 0;
}

void do_test(c *connie_Connie)
{
    // TODO テストを実装する。
}

// TODO テスト関数を追加する場合は、ここにテスト関数の定義を追加する。
```

## 使用方法

テストコードに`connie_sugar.h`もしくは`connie.h`をincludeする。

`connie.h`はConnieの全機能を提供し、`connie_sugar.h`はそれらの一部関数を略記で利用可能とするためのヘッダファイルである。

`connie_sugar.h`は`connie.h`をincudeしているため、どちらか一方のみincludeすればよい。

```c
#include <connie_sugar.h> // or #include <connie.h>
```

`main`関数では、`connie_Connie`オブジェクトを生成してテスト関数（定義方法は後述）を実行する。

その後テスト結果を表示して`connie_Connie`オブジェクトを破棄する。

```c
// テスト関数
void do_test(connie *connie_Connie);

int main(void)
{
    // connie_Connieオブジェクトを生成する。
    connie_Connie *c = connie_new(__FILE__);

    // テストを実行する。
    // connie_test()はテスト関数の数により複数回実行可
    // connie_sugar.hをincludeしている場合はconnie_test()の代わりにTEST()でも可
    connie_test(c, "caption", do_test);

    // 結果を表示する。
    connie_print(c);

    // connie_Connieオブジェクトを破棄する。
    connie_delete(c);

    return 0;
}
```

## テスト関数の定義

テストを実行する関数は以下のとおり定義する。

```c
void do_test(connie_Connie *connie);
```

例

```c
void do_test(connie_Connie *connie)
{
    actual1 = foo();
    connie_assert_equal_int(connie, 100, actual1, __LINE__);

    actual2 = bar();
    connie_assert_equal_string(connie, "OK", actual2, __LINE__);
}
```

## アサーション関数

テスト関数内でテスト対象の実行結果のアサーションに使用する。

### 値の等値性を判定する

これらの関数は、`expected`と`actual`の値が同じかを判定する。

`char`型のアサーション

```c
// connie.h
void connie_assert_equal_char(connie_Connie *connie, char expected, char actual, int line);

// connie_sugar.h
#define A_EQL_CHAR(connie, expected, actual) connie_assert_equal_char(connie, expected, actual, __LINE__)
```

`unsigned char`型のアサーション

```c
// connie.h
void connie_assert_equal_uchar(connie_Connie *connie, unsigned char expected, unsigned char actual, int line);

// connie_sugar.h
#define A_EQL_UCHAR(connie, expected, actual) connie_assert_equal_uchar(connie, expected, actual, __LINE__)
```

`int`型のアサーション

```c
// connie.h
void connie_assert_equal_int(connie_Connie *connie, int expected, int actual, int line);

// connie_sugar.h
#define A_EQL_INT(connie, expected, actual) connie_assert_equal_int(connie, expected, actual, __LINE__)
```

`unsigned int`型のアサーション

```c
// connie.h
void connie_assert_equal_uint(connie_Connie *connie, unsigned int expected, unsigned int actual, int line);

// connie_sugar.h
#define A_EQL_UINT(connie, expected, actual) connie_assert_equal_uint(connie, expected, actual, __LINE__)
```

`long`型のアサーション

```c
// connie.h
void connie_assert_equal_long(connie_Connie *connie, long expected, long actual, int line);

// connie_sugar.h
#define A_EQL_LONG(connie, expected, actual) connie_assert_equal_long(connie, expected, actual, __LINE__)
```

`unsigned long`型のアサーション

```c
// connie.h
void connie_assert_equal_ulong(connie_Connie *connie, unsigned long expected, unsigned long actual, int line);

// connie_sugar.h
#define A_EQL_ULONG(connie, expected, actual) connie_assert_equal_ulong(connie, expected, actual, __LINE__)
```

ポインタが`NULL`であることのアサーション

```c
// connie.h
void connie_assert_null(connie_Connie *connie, void *actual, int line);

// connie_sugar.h
#define A_NULL(connie, actual) connie_assert_null(connie, actual, __LINE__)
```

ポインタが非`NULL`であることのアサーション

```c
// connie.h
void connie_assert_not_null(connie_Connie *connie, void *actual, int line);

// connie_sugar.h
#define A_NOT_NULL(connie, actual) connie_assert_not_null(connie, actual, __LINE__)
```

`const char *`型（文字列）のアサーション

```c
// connie.h
void connie_assert_equal_string(connie_Connie *connie, const char *expected, const char *actual, int line);

// connie_sugar.h
#define A_EQL_STRING(connie, expected, actual) connie_assert_equal_string(connie, expected, actual, __LINE__)
```

### 配列の内容が一致するかを判定する

これらの関数は、`expected`と`actual`それぞれに含まれる要素が同じかを判定する。

引数`ignore_order`は、要素の順序を判定基準に加えるか否かを表し、順序も判定する場合は`connie_NOT_IGNORE_ORDER`を、順序を無視する場合は`connie_IGNORE_ORDER`を指定する。

`char`型配列のアサーション

```c
// connie.h
void connie_assert_equal_char_array(connie_Connie *connie, const char expected[], size_t len, const char actual[], int ignore_order, int line);

// connie_sugar.h
#define A_EQL_CHAR_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_char_array(connie, expected, len, actual, ignore_order, __LINE__)
```

`unsigned char`型配列のアサーション

```c
// connie.h
void connie_assert_equal_uchar_array(connie_Connie *connie, const unsigned char expected[], size_t len, const unsigned char actual[], int ignore_order, int line);

// connie_sugar.h
#define A_EQL_UCHAR_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_uchar_array(connie, expected, len, actual, ignore_order, __LINE__)
```

`int`型配列のアサーション

```c
// connie.h
void connie_assert_equal_int_array(connie_Connie *connie, const int expected[], size_t len, const int actual[], int ignore_order, int line);

// connie_sugar.h
#define A_EQL_INT_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_int_array(connie, expected, len, actual, ignore_order, __LINE__)
```

`unsigned int`型配列のアサーション

```c
// connie.h
void connie_assert_equal_uint_array(connie_Connie *connie, const unsigned int expected[], size_t len, const unsigned int actual[], int ignore_order, int line);

// connie_sugar.h
#define A_EQL_UINT_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_uint_array(connie, expected, len, actual, ignore_order, __LINE__)
```

`long`型配列のアサーション

```c
// connie.h
void connie_assert_equal_long_array(connie_Connie *connie, const long expected[], size_t len, const long actual[], int ignore_order, int line);

// connie_sugar.h
#define A_EQL_LONG_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_long_array(connie, expected, len, actual, ignore_order, __LINE__)
```

`unsigned long`型配列のアサーション

```c
// connie.h
void connie_assert_equal_ulong_array(connie_Connie *connie, const unsigned long expected[], size_t len, const unsigned long actual[], int ignore_order, int line);

// connie_sugar.h
#define A_EQL_ULONG_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_ulong_array(connie, expected, len, actual, ignore_order, __LINE__)
```
