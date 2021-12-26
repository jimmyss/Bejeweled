# Sqlite 配置
## Qt的Sql组件导入

项目使用qt自带的QtSql和sqlite数据库，不需要数据库服务进程，可在内存中实现，方便配置。

使用QtSql，需在Qt设置中添加sql组件。在扩展-Qt Vs Tools-qt project settings中的Qt modules添加
'sql;'即可使用。

## 可考虑使用的插件

在 拓展-管理拓展-联机 中可安装SQLite and SQL Sever Compact Toolbox 实现对Sqlite数据库的可视化操作

## API

`int login(QString name, QString password)`

-1为操作失败，0为登录失败（密码错误或未注册），1为成功登录

`int registrate(QString name, QString password)`

-1为操作失败，0为注册失败（用户名重复），1为成功注册

`int updateRank(QString name, int rank)`

-1更新失败，1更新成功

**实例：**

```cpp
int res = u.login("123", "123");
if (res == -1) {
    qDebug() << "error";
}
if (res == 0) {
    qDebug() << "wrong pass/not registrate";
}
if (res == 1) {
    qDebug() << "login";
}
```

```cpp
int res = u.registrate("ccc", "111");
if (res == -1) {
    qDebug() << "error";
}
if (res == 0) {
    qDebug() << "same name";
}
if (res == 1) {
    qDebug() << "regs";
}
```

## 后续

考虑加入排行榜，使用Qt中的table view展示，密码列可通过设置bind屏蔽

[Table View展示信息](https://blog.csdn.net/pejay23/article/details/106321392)