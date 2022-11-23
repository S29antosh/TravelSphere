#include "registryforcompanies.h"
#include "ui_registryforcompanies.h"


registryForCompanies::registryForCompanies(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registryForCompanies)
{
    ui->setupUi(this);
}

registryForCompanies::~registryForCompanies()
{
    delete ui;
}



void registryForCompanies::on_register_PushButton_clicked()
{
    QSqlDatabase db01 = QSqlDatabase::addDatabase("QSQLITE");

    db01.setDatabaseName("C:/Users/PC/travelSphere/database/travelSphere01.sqlite");
    QDate EstdDate = ui->Established_dateEdit_2->date();
    QString DOE = EstdDate.toString() ;
    QString CompanyName = ui->CompanyName->text();
    QString location = ui->location->text();
    QString nation = ui->Nation->text();
    QString comEmail = ui->CompanyEmail->text();
    QString username = ui->Company_Username->text();
    QString password = ui->passwordComp->text();
    QString documentNo = ui->documentNo->text();
    QString docType = ui->comboBox->currentText();
    QString Contact = ui->ContactNo->text();

    db01.open();
     QSqlQuery comDet;
     //preparing and binding the values
     comDet.prepare("INSERT INTO Companies('Company Name','Location','ESTD Date','Nation','Documentation No:','Documentation Type','Company Contact No', 'Email' ,'Company Username','Password')VALUES(:Company Name,:Location,:ESTD Date,:Nation,:Documentation No:,:Documentation Type,:Company Contact No,:Email,:Company Username, :Password,'sucess')");
    comDet.bindValue(":Company Name", CompanyName);
    comDet.bindValue(":Location", location);
    comDet.bindValue(":ESTD Date",EstdDate);
    comDet.bindValue(":Nation",nation);
    comDet.bindValue(":Documentation No:",documentNo);
    comDet.bindValue(":Documentation Type",docType);
    comDet.bindValue(":Company Contact No",Contact);
    comDet.bindValue("Email", comEmail) ;
    comDet.bindValue(":Company Username",username);
    comDet.bindValue(":Password",password);

 if(ui->termsAndConditions->isChecked())
 {
     if(CompanyName != "" && location != "" && DOE != "" && nation != "" && username != "" && comEmail != "" && Contact != "" && password != "")
     {


         int em=0,contct=0,pw=0;
         QRegularExpression re("(\\w+)(\\w*)@(\\w+)(\\.(\\w+))+");
         if(re.match(comEmail).hasMatch()) em = 1;
         if(Contact.length()>=10)  contct=1;
         if(password.length()>=8)   pw=1;

         if(pw)
         {
             if(em)
             {
                 if(contct)
                 {

                 QSqlQuery qry,check;
                 int user_id=0;
                 if(check.exec("select * from Companies where Email='"+comEmail+"' "))
                    {
                         while(check.next())
                        {
                          user_id++;
                        }
                    }
                 if(user_id==1)
                    {
                       QMessageBox::information(this,"Error","Your account is already registered with this email.");
                    }

                  }


            }

         }
      }
    }

}
