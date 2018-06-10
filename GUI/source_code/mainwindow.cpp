#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QTableWidget>
#include<QWidget>
#include<QLineEdit>
#include<QComboBox>
#include<QLabel>
#include<QFileDialog>
#include<QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(QStringLiteral(":/icons/student")));

    // 信号机制，连接按钮和事件
    connect(ui->AllButton, &QPushButton::clicked, this, [=](bool check){
        showAll(check, msg);
    });
    connect(ui->AddButton, &QPushButton::clicked, this, &MainWindow::addMsg);
    connect(ui->ReviseButton, &QPushButton::clicked, this, &MainWindow::reviseMsg);
    connect(ui->DeleteButton, &QPushButton::clicked, this, &MainWindow::deleteMsg);
    connect(ui->SortButton, &QPushButton::clicked, this, &MainWindow::sortMsg);
    connect(ui->SearchButton, &QPushButton::clicked, this, &MainWindow::queryMsg);
    connect(ui->MergeButton, &QPushButton::clicked, this, &MainWindow::mergeMsg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 显示所有信息
void MainWindow::showAll(bool check, StudentMsg* ms){
   
    // 判断是否为空， 空则弹出提示框
    if(ms->name.empty()){
        QMessageBox msgBox;
        msgBox.information(this,tr("attention"), tr("empty yet"));
    }else{
        // 创建表格
        QTableWidget *table = new QTableWidget(ui->mainSpace);
        table->setWindowTitle(tr("Student Message"));
        StudentMsg *p = ms;
        int n = 0;
        for(;p!=NULL;p = p->next)
            n++;
        p = nullptr;
        delete p;
        table->setColumnCount(6);
        table->setRowCount(n);
        table->resize(620, 400);
        QStringList header;
        header << "name" << "id" << "cpp" << "java" << "math" << "total";
        table->setHorizontalHeaderLabels(header);
        StudentMsg *q=ms;
        for(int i=0;i<n;i++){
            table->setItem(i, 0, new QTableWidgetItem(s2q(q->name)));
            table->setItem(i, 1, new QTableWidgetItem(s2q(q->id)));
            table->setItem(i, 2, new QTableWidgetItem(s2q(q->cpp)));
            table->setItem(i, 3, new QTableWidgetItem(s2q(q->java)));
            table->setItem(i, 4, new QTableWidgetItem(s2q(q->math)));
            table->setItem(i, 5, new QTableWidgetItem(s2q(q->total)));
            q = q->next;
        }
        q = nullptr;
        delete q;
        table->show();


    }
}

// 添加记录，弹出对话框
void MainWindow::addMsg(){
    QWidget *addWidget;
    addWidget = new QWidget;
    addWidget->setWindowTitle("Add New Message");
    addWidget->resize(300,400);
    // 添加垂直布局
    QVBoxLayout *layout = new QVBoxLayout;
    QLineEdit *nameEdit = new QLineEdit(addWidget);
   
    // 加入输入框，设置填充值
    nameEdit->setPlaceholderText("name");
    QLineEdit *idEdit = new QLineEdit(addWidget);
    idEdit->setPlaceholderText("id");
    QLineEdit *cppEdit = new QLineEdit(addWidget);
    cppEdit->setPlaceholderText("cpp");
    QLineEdit *javaEdit = new QLineEdit(addWidget);
    javaEdit->setPlaceholderText("java");
    QLineEdit *mathEdit = new QLineEdit(addWidget);
    mathEdit->setPlaceholderText("math");
    QPushButton *addBtn = new QPushButton("Add",addWidget);
    layout->addWidget(nameEdit);
    layout->addWidget(idEdit);
    layout->addWidget(cppEdit);
    layout->addWidget(javaEdit);
    layout->addWidget(mathEdit);
    layout->addWidget(addBtn);
    addWidget->setLayout(layout);

    // 绑定回车键和按钮
    addWidget->connect(mathEdit, &QLineEdit::returnPressed, addBtn, [=]{
        addBtn->clicked();
    });

    // 按钮设置槽函数, 使用lambda表达式
    addWidget->connect(addBtn, &QPushButton::clicked, this,[=]{
        string aname = q2s(nameEdit->text());
        string aid = q2s(idEdit->text());
        string acpp = q2s(cppEdit->text());
        string ajava = q2s(javaEdit->text());
        string amath = q2s(mathEdit->text());
        stumsg(aname, aid, stoi(acpp), stoi(ajava), stoi(amath));
        Admin::addMsg(addWidget);
        showAll(true, msg);
        addWidget->close();
    });

    addWidget->show();
}

// 修改记录, 各项设置跟addMsg相同
void MainWindow::reviseMsg(){
    QWidget *reviseWidget;
    reviseWidget = new QWidget;
    reviseWidget->setWindowTitle("Revise Message");
    reviseWidget->resize(300,400);
    QVBoxLayout *layout = new QVBoxLayout;
    QLineEdit *nameEdit = new QLineEdit(reviseWidget);

    nameEdit->setPlaceholderText("name");
    QLineEdit *idEdit = new QLineEdit(reviseWidget);
    idEdit->setPlaceholderText("id");
    QLineEdit *cppEdit = new QLineEdit(reviseWidget);
    cppEdit->setPlaceholderText("cpp");
    QLineEdit *javaEdit = new QLineEdit(reviseWidget);
    javaEdit->setPlaceholderText("java");
    QLineEdit *mathEdit = new QLineEdit(reviseWidget);
    mathEdit->setPlaceholderText("math");
    QPushButton *reviseBtn = new QPushButton("Revise",reviseWidget);
    layout->addWidget(nameEdit);
    layout->addWidget(idEdit);
    layout->addWidget(cppEdit);
    layout->addWidget(javaEdit);
    layout->addWidget(mathEdit);
    layout->addWidget(reviseBtn);
    reviseWidget->setLayout(layout);

    reviseWidget->connect(mathEdit, &QLineEdit::returnPressed, reviseBtn, [=]{
        reviseBtn->clicked();
    });

    reviseWidget->connect(reviseBtn, &QPushButton::clicked, this,[=]{
        string aname = q2s(nameEdit->text());
        string aid = q2s(idEdit->text());
        string acpp = q2s(cppEdit->text());
        string ajava = q2s(javaEdit->text());
        string amath = q2s(mathEdit->text());
        stumsg(aname, aid, stoi(acpp), stoi(ajava), stoi(amath));
        Admin::reviseMsg(reviseWidget);
        showAll(true, msg);
        reviseWidget->close();
    });

    reviseWidget->show();
}

// 删除记录
void MainWindow::deleteMsg(){
    QWidget *deleteWidget;
    deleteWidget = new QWidget;
    deleteWidget->setWindowTitle("Delete Message");
    deleteWidget->resize(230,150);

    QVBoxLayout *layout = new QVBoxLayout;

    QLineEdit *idEdit = new QLineEdit(deleteWidget);
    idEdit->setPlaceholderText("id");
    QPushButton *delBtn = new QPushButton("Delete",deleteWidget);
    layout->addWidget(idEdit);
    layout->addWidget(delBtn);
    deleteWidget->setLayout(layout);

    deleteWidget->connect(idEdit, &QLineEdit::returnPressed, delBtn, [=]{
        delBtn->clicked();
    });

    deleteWidget->connect(delBtn, &QPushButton::clicked, this,[=]{
        string aid = q2s(idEdit->text());

        Admin::deleteMsg(aid, deleteWidget);
        showAll(true, msg);
        deleteWidget->close();
    });
    deleteWidget->show();
}

// 排序
void MainWindow::sortMsg(){
    QWidget *sortWidget = new QWidget;
    sortWidget->setWindowTitle("Sort Messages");
    sortWidget->resize(230, 250);

    QVBoxLayout *layout = new QVBoxLayout;

    // 添加下拉框
    QComboBox *type = new QComboBox;
    QComboBox *reverse = new QComboBox;
    // 设置下拉框内容
    QStringList allType;
    allType << "name" << "id" << "cpp" << "java" << "math" << "total";
    type->addItems(allType);
    reverse->addItem("Yes");
    reverse->addItem("No");
    // 添加标签
    QLabel *typeLabel = new QLabel("ordered by");
    QLabel *reverseLabel = new QLabel("reverse?");
    QPushButton *sortBtn = new QPushButton("Sort", sortWidget);
    layout->addWidget(typeLabel);
    layout->addWidget(type);
    layout->addWidget(reverseLabel);
    layout->addWidget(reverse);
    layout->addWidget(sortBtn);

    sortWidget->setLayout(layout);

    sortWidget->connect(sortBtn, &QPushButton::clicked, this, [=]{
        string tp = q2s(type->currentText());
        string rev = q2s(reverse->currentText());
        bool isrev = (rev=="Yes"?true:false);
        sorting(tp, isrev);
        showAll(true, msg);
        sortWidget->close();
    });
    sortWidget->show();
}

// 查询记录
void MainWindow::queryMsg(){
    QWidget *queryWidget = new QWidget;
    queryWidget->setWindowTitle("Query Messages");
    queryWidget->resize(300, 100);

    // 添加栅格布局
    QGridLayout *layout = new QGridLayout;
    QComboBox *type = new QComboBox;
    QComboBox *compare = new QComboBox;
    QStringList allType;
    allType << "name" << "id" << "cpp" << "java" << "math" << "total";
    type->addItems(allType);
    QStringList allCompare;
    allCompare << "=" << "<" << ">" << "<=" << ">=" << "!=";
    compare->addItems(allCompare);

    QLabel *select = new QLabel("Select");

    QLineEdit *contentEdit = new QLineEdit(queryWidget);

    QPushButton *queryBtn = new QPushButton("Query", queryWidget);

    // 设置布局
    layout->addWidget(select, 0, 0, 1, 1);
    layout->addWidget(type, 1, 0);
    layout->addWidget(compare, 1, 1);
    layout->addWidget(contentEdit, 1, 2);
    layout->addWidget(queryBtn, 2, 1, 1, 1);

    queryWidget->setLayout(layout);

    queryWidget->connect(contentEdit, &QLineEdit::returnPressed, queryBtn, [=]{
        queryBtn->clicked();
    });

    queryWidget->connect(queryBtn, &QPushButton::clicked, this, [=]{
        // 获取值
        string tp = q2s(type->currentText());
        string com = q2s(compare->currentText());
        string content = q2s(contentEdit->text());
        StudentMsg* tem =  Admin::queryMsg(tp, content, com, queryWidget);
        if(!tem->name.empty())
            showAll(true, tem);
        queryWidget->close();
    });
    queryWidget->show();
}

// 合并文件
void MainWindow::mergeMsg(){
    // 调用系统的文件对话框,添加过滤，仅显示txt文件,获取路径
    QString path = QFileDialog::getOpenFileName(this, tr("Select File"),
                                                ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()){
        string paths = q2s(path);
        merge(paths);
        showAll(true, msg);
    }
}

// string 转 QString
QString MainWindow::s2q(string s){
    return QString(QString::fromLocal8Bit(s.c_str()));
}

// QString 转 string
string MainWindow::q2s(QString s){
    return string((const char *)s.toLocal8Bit());
}

