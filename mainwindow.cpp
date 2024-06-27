#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQueryModel>


//Unfortunately we made a mistake and the mistake is we renamed the stackwidget into first_page.
//so, here first page means stackwidget page.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->first_page->setCurrentIndex(0);

    //database;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\Bus_management system/bus.db");
    db.open();
    qDebug()<<db. isOpen();
    if (db.open()) {
        qDebug() << "Database opened successfully.";
    } else {
        //qDebug() << "Failed to open the database:" << db.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}






void MainWindow::on_user_login_button_clicked()
{
    email = ui->email_input->text();
    password = ui->pass_input->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Email and password cannot be empty");
    }
    else {
        QSqlQuery q1;
        q1.exec("SELECT * FROM customer_info WHERE email='" + email + "' AND password='" + password + "'");
        if (q1.next()) {
            QMessageBox::information(this, "Log In", "Successfully Logged In");
            ui->first_page->setCurrentIndex(2);
            //qDebug() << q1.value(1).toString();
            ui->email_label->setText(q1.value(1).toString());
            ui->name_label->setText(q1.value(0).toString());
            ui->payment_name_label->setText(q1.value(0).toString());

            ui->invoice_email_label->setText(q1.value(1).toString());
            ui->payment_contact_label->setText(q1.value(3).toString());
            // ui->seat_label->setText(q1.value(0).toString());

            ui->invoice_name_label->setText(q1.value(0).toString());
            //ui->passenger_email->setText(q1.value(1).toString());
            ui->invoice_mobile_label->setText(q1.value(3).toString());
            //qDebug() << q1.value(1).toString();
        }
        else {
            QMessageBox::warning(this, "Login", "Wrong email or password");
        }

        ui->email_input->clear();
        ui->pass_input->clear();
    }
}


void MainWindow::on_signup_button_clicked()
{
    name_sign=ui->name->text();
    email_sign=ui->email->text();
    password_sign=ui->password->text();
    contact_sign=ui->contact->text();
    confirm_pass_sign=ui->confirm_password->text();
    //if the email is available or not;
    QSqlQuery checkQuery;
    checkQuery.exec("SELECT * FROM customer_info WHERE email='"+email_sign+"'");
    {
        if (checkQuery.next()) {
            QMessageBox::warning(this, "Sign Up", "This  email already exists.");
            ui->name->clear();
            ui->email->clear();
            ui->password->clear();
            ui->contact->clear();
            ui->confirm_password->clear();
            return;
        }
    }
    if (name_sign.isEmpty() || email_sign.isEmpty() || password_sign.isEmpty()) {
        QMessageBox::warning(this, "Login", "Name, Email and password cannot be empty");
    }
    //password mismacth case and adding information to ;
    else if(password_sign==confirm_pass_sign)
    {
        QSqlQuery q2;
        q2.exec("INSERT INTO customer_info (name,email,password,contact) VALUES('"+name_sign+"','"+email_sign+"','"+password_sign+"','"+contact_sign+"') ");
        QMessageBox::information(this, "Sign Up","Sign Up Successfully");
        ui->name->clear();
        ui->email->clear();
        ui->password->clear();
        ui->contact->clear();
        ui->confirm_password->clear();
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::information(this, "Sign Up","password mismatch");
        ui->name->clear();
        ui->email->clear();
        ui->password->clear();
        ui->contact->clear();
        ui->confirm_password->clear();
        return;

    }

}




void MainWindow::on_user_button_clicked()
{
   ui->first_page->setCurrentIndex(1);
}


void MainWindow::on_search_button_2_clicked()
{
   if(Q1==Q2){
        QMessageBox::information(this, "Destination","Please Select Correct Destination");
   }
   else{

    ui->first_page->setCurrentIndex(3);
   }
}


void MainWindow::on_View_seat_btn_clicked()
{


   QSqlQuery confirmQuery;
   confirmQuery.exec("SELECT seat, confirm FROM seat");
   while (confirmQuery.next()) {
    QString confirmedSeat = confirmQuery.value(0).toString();
    int confirmValue = confirmQuery.value(1).toInt();
    //forA1seat;
    if (confirmValue == 1) {
            // Seat is confirmed, set background color to red
            if (confirmedSeat == "A1") {
                ui->A1->setStyleSheet("background-color: red;");
            }
            // After comfiming the seats push button color change code.
    } else {
            if (confirmedSeat == "A1") {
                ui->A1->setStyleSheet("background-color: yellow;");
            }
    }
    //forA2seat
    if (confirmValue == 1) {
            if (confirmedSeat == "A2") {
                ui->A2->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "A2") {
                ui->A2->setStyleSheet("background-color: yellow;");
            }
    }

    //forA3seat
    if (confirmValue == 1) {
            if (confirmedSeat == "A3") {
                ui->A3->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "A3") {
                ui->A3->setStyleSheet("background-color: yellow;");
            }
    }

    //forB1seat
    if (confirmValue == 1) {
            if (confirmedSeat == "B1") {
                ui->B1->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "B1") {
                ui->B1->setStyleSheet("background-color: yellow;");
            }
    }

    //forB2seat
    if (confirmValue == 1) {
            if (confirmedSeat == "B2") {
                ui->B2->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "B2") {
                ui->B2->setStyleSheet("background-color: yellow;");
            }
    }

    //forB3seat
    if (confirmValue == 1) {
            if (confirmedSeat == "B3") {
                ui->B3->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "B3") {
                ui->B3->setStyleSheet("background-color: yellow;");
            }
    }

    //forC1seat
    if (confirmValue == 1) {
            if (confirmedSeat == "C1") {
                ui->C1->setStyleSheet("background-color: red;");
            }
    } else {
            // Seat is not confirmed, set background color to yellow
            if (confirmedSeat == "C1") {
                ui->C1->setStyleSheet("background-color: yellow;");
            }
    }

    //forC2seat
    if (confirmValue == 1) {
            if (confirmedSeat == "C2") {
                ui->C2->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "C2") {
                ui->C2->setStyleSheet("background-color: yellow;");
            }
    }

    //forC3seat
    if (confirmValue == 1) {
            if (confirmedSeat == "C3") {
                ui->C3->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "C3") {
                ui->C3->setStyleSheet("background-color: yellow;");
            }
    }

    //forD1seat
    if (confirmValue == 1) {
            if (confirmedSeat == "D1") {
                ui->D1->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "D1") {
                ui->D1->setStyleSheet("background-color: yellow;");
            }
    }

    //forD2seat
    if (confirmValue == 1) {
            if (confirmedSeat == "D2") {
                ui->D2->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "D2") {
                ui->D2->setStyleSheet("background-color: yellow;");
            }
    }

    //forD3seat
    if (confirmValue == 1) {
            if (confirmedSeat == "D3") {
                ui->D3->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "D3") {
                ui->D3->setStyleSheet("background-color: yellow;");
            }
    }

    //forE1seat
    if (confirmValue == 1) {
            if (confirmedSeat == "E1") {
                ui->E1->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "E1") {
                ui->E1->setStyleSheet("background-color: yellow;");
            }
    }

    //forE2seat
    if (confirmValue == 1) {
            if (confirmedSeat == "E2") {
                ui->E2->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "E2") {
                ui->E2->setStyleSheet("background-color: yellow;");
            }
    }

    //forE3seat
    if (confirmValue == 1) {
            if (confirmedSeat == "E3") {
                ui->E3->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "E3") {
                ui->E3->setStyleSheet("background-color: yellow;");
            }
    }

    //forF1seat
    if (confirmValue == 1) {
            if (confirmedSeat == "F1") {
                ui->F1->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "F1") {
                ui->F1->setStyleSheet("background-color: yellow;");
            }
    }

    //forF2seat
    if (confirmValue == 1) {
            if (confirmedSeat == "F2") {
                ui->F2->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "F2") {
                ui->F2->setStyleSheet("background-color: yellow;");
            }
    }

    //forF3seat
    if (confirmValue == 1) {
            if (confirmedSeat == "F3") {
                ui->F3->setStyleSheet("background-color: red;");
            }
    } else {
            if (confirmedSeat == "F3") {
                ui->F3->setStyleSheet("background-color: yellow;");
            }    
    }


   }
   //which seats you have selected those data will come in your ui.
   QString user = ui->email_label->text();
   QSqlQuery query;

   // searching seats code of logging user
   query.prepare("SELECT seat FROM seat WHERE user = :user");
   query.bindValue(":user", user);

   if (query.exec()) {
    QString allSeats;

    while (query.next()) {
    QString seat = query.value(0).toString();
    allSeats += "" + seat + " ";
    }

    ui->seat_label_2->setText(allSeats);
   } else {
    qDebug() << "Query execution failed: " << query.lastError().text();
   }

    ui->first_page->setCurrentIndex(4);
}

//after choosing seats next button.
void MainWindow::on_next_button_clicked()
{
    QString emailLabelValue = ui->email_label->text();
    QSqlQuery query20;
    query20.prepare("SELECT COUNT(*) FROM seat WHERE user = :emailLabelValue");
    query20.bindValue(":emailLabelValue", emailLabelValue);

    if (query20.exec()) {
    if (query20.next()) {
    count = query20.value(0).toInt();

    if (count > 4) {
        QMessageBox::information(this, "Count Info", "Sir you can't choose more than 4 seats");
    }
    else if(count < 1)
    {
        QMessageBox::information(this, "Count Info", "Please sir you have choose least One seat for going next page");
    }
    else if(count >=1 && count <= 4)
    {
        ui->first_page->setCurrentIndex(5);

        QString user = ui->email_label->text();

        QSqlQuery query;
        query.prepare("SELECT seat FROM seat WHERE user = :user");
        query.bindValue(":user", user);

        if (query.exec()) {
                QString allSeats;

                while (query.next()) {
                    QString seat = query.value(0).toString();
                    allSeats += "" + seat + " ";
                }

                ui->seat_label_3->setText(allSeats);
        } else {
                qDebug() << "Query execution failed: " << query.lastError().text();
                }
            }
        }
    }
}


void MainWindow::on_proceed_button_passenger_clicked()
{
   ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_purchase_button_clicked()
{
    ui->first_page->setCurrentIndex(12);
}


void MainWindow::on_admin_button_clicked()
{
    ui->first_page->setCurrentIndex(6);
}


void MainWindow::on_admin_login_button_clicked()
{
    admin_email = ui->admin_email_input->text();
    admin_password = ui->admin_password_input->text();

    if (admin_email.isEmpty() || admin_password.isEmpty()) {
    QMessageBox::warning(this, "Login", "Email and password cannot be empty");
    }
    else {
    QSqlQuery q3;
    q3.exec("SELECT * FROM admin WHERE email='" + admin_email + "' AND password='" + admin_password + "'");
    if (q3.next()) {
            QMessageBox::information(this, "Log In", "Successfully Logged In");
            ui->first_page->setCurrentIndex(7);
            //ui->name_label->setText(q1.value(0).toString());
    }
    else {
            QMessageBox::warning(this, "Login", "Wrong email or password");
    }

    ui->admin_email_input->clear();
    ui->admin_password_input->clear();
    }



}


void MainWindow::on_Admin_panel_next_clicked()
{
    ui->first_page->setCurrentIndex(8);
}


void MainWindow::on_Driver_next_clicked()
{
    ui->first_page->setCurrentIndex(9);
}


void MainWindow::on_des_back_btn_clicked()
{
   ui->first_page->setCurrentIndex(1);
}


void MainWindow::on_signlog_back_clicked()
{
    ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_bus_sel_back_btn_clicked()
{
    ui->first_page->setCurrentIndex(2);
}


void MainWindow::on_from_combo_box_currentTextChanged(const QString &arg1)
{
    ui->from_label->setText(arg1);
    ui->journey_from->setText(arg1);
     Q1 = arg1;
}


void MainWindow::on_to_combo_box_currentTextChanged(const QString &arg1)
{
    ui->to_label->setText(arg1);
    ui->journey_to->setText(arg1);
    Q2=arg1;
}


void MainWindow::on_date_combo_box_userDateChanged(const QDate &date)
{

}


void MainWindow::on_date_combo_box_dateChanged(const QDate &date)
{
    QString dateString = date.toString("dd.MM.yyyy");
    ui->date_label->setText(dateString);
    ui->invoice_date_label->setText(dateString);
}


void MainWindow::on_payment_back_clicked()
{
    ui->first_page->setCurrentIndex(4);
}


void MainWindow::on_seat_selec_back_btn_clicked()
{
    ui->first_page->setCurrentIndex(3);
}








void MainWindow::on_profile_button_clicked()
{
    QString comboBox_select = ui->comboBox_for_profiles->currentText();

    if(comboBox_select == "Customers Info"){



    QSqlQueryModel * modal = new QSqlQueryModel (ui->tableView_profiles);
    modal-> setQuery(QString ("select name,email,contact from customer_info "));
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Email"));
    //modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Password"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));

    ui->tableView_profiles-> setModel(modal);


    }


    if(comboBox_select == "Seat info"){



    QSqlQueryModel * modal = new QSqlQueryModel (ui->tableView_profiles);
    modal-> setQuery(QString ("select seat,user,des_from,des_to,confirm,des_date,payment from seat "));
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Seat"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Email"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination From"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Destination To"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Confirm"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Destination Date"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("Payment"));

    ui->tableView_profiles-> setModel(modal);


    }

    if(comboBox_select == "Driver info"){



    QSqlQueryModel * modal = new QSqlQueryModel (ui->tableView_profiles);
    modal-> setQuery(QString ("select name,contact,email from Driver_info "));
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Contact"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    //modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));

    ui->tableView_profiles-> setModel(modal);


    }
    if(comboBox_select == "Job Applicants"){



    QSqlQueryModel * modal = new QSqlQueryModel (ui->tableView_profiles);
    modal-> setQuery(QString ("select name,address,email,contact,experience from job_applicants "));
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Address"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Contact"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Experience"));

    ui->tableView_profiles-> setModel(modal);


    }
}


void MainWindow::on_complain_box_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel (ui->complain_table);
    modal-> setQuery(QString ("select complain from customerComplain "));
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Customer Complain Here"));



    ui->complain_table-> setModel(modal);
}

// Admin Confirm
void MainWindow::on_confirm_seatbooking_btn_clicked()
{
    confirm_email = ui->confirm_seat_input_email->text();
    confirm_to_1 = ui->confirm_to_input->text();

    QSqlQuery qry6;
    qry6.prepare("update seat set confirm = :confirm_value where user = :user_email");
    qry6.bindValue(":confirm_value", confirm_to_1);
    qry6.bindValue(":user_email", confirm_email);

    if (qry6.exec()) {
    QMessageBox::information(this, "Update Info", "Updated Successfully");
    } else {
    QMessageBox::warning(this, "Update Info", "Invalid email or update failed");
    }

    ui->confirm_seat_input_email->clear();
    ui->confirm_to_input->clear();
}





void MainWindow::on_job_apply_clicked()
{
    ui->first_page->setCurrentIndex(11);
}


void MainWindow::on_Home_page_button_clicked()
{
    ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_Home_page_button_2_clicked()
{
    ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_Home_page_button_3_clicked()
{
    QMessageBox::information(this, "Home page", "Please wait for some time. After Admin approval you can show your ticket information in Download Ticket");
     ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_Apply_job_button_clicked()
{

     job_driver_name=ui->job_name_input->text();
     job_driver_address=ui->Job_address_input->text();
     job_driver_contact=ui->job_contact_number_input->text();
     job_driver_experience=ui->job_experience_input->text();
     job_driver_email=ui->job_email_input->text();
     //if the email is available or not;
     QSqlQuery checkQuery10;
     checkQuery10.exec("SELECT * FROM job_applicants WHERE email='"+job_driver_email+"'");
     {
    if (checkQuery10.next()) {
            QMessageBox::warning(this, "Sign Up", "This  email already exists.");
            ui->job_name_input->clear();
            ui->job_email_input->clear();
            ui->job_contact_number_input->clear();
            ui->Job_address_input->clear();
            ui->job_experience_input->clear();
            return;
    }
     }
     if (job_driver_name.isEmpty() || job_driver_address.isEmpty() ||job_driver_email.isEmpty() ) {
    QMessageBox::warning(this, "Login", "Name, email, address cannot be empty");
     }
     else {
    QSqlQuery q10;
    q10.exec("INSERT INTO job_applicants (name,address,email,contact,experience) VALUES('"+job_driver_name+"','"+job_driver_address+"','"+job_driver_email+"','"+job_driver_contact+"','"+job_driver_experience+"') ");
    QMessageBox::information(this, "Job Apply","Job information added successfully");
    ui->job_name_input->clear();
    ui->job_email_input->clear();
    ui->job_contact_number_input->clear();
    ui->Job_address_input->clear();
    ui->job_experience_input->clear();
     }


}


void MainWindow::on_Driver_add_submit_button_clicked()
{
    add_driver_name = ui->add_driver_name_input->text();
    add_driver_email = ui->add_driver_email_input->text();
    add_driver_contact = ui->add_driver_contact_input->text();

    if (add_driver_name.isEmpty() || add_driver_email.isEmpty()) {
    QMessageBox::information(this, "Submit", "Name and email cannot be empty");
    }
    else{
    QSqlQuery query11;
    query11.exec("INSERT INTO Driver_info (name,contact,email) VALUES('"+add_driver_name+"','"+add_driver_contact+"','"+add_driver_email+"')");

    QMessageBox :: information(this,"Driver Info.","Driver Added Successful");

    ui->add_driver_name_input->clear();
    ui->add_driver_email_input->clear();
    ui->add_driver_contact_input->clear();
    }

}


void MainWindow::on_admin_display_back_button_clicked()
{
   ui->first_page->setCurrentIndex(8);
}


void MainWindow::on_Driver_delete_button_clicked()
{
   driver_delete_email = ui->driver_delete_email_input->text();
   driver_admin_password = ui->admin_pass_input->text();
   QSqlQuery query12;
   query12.exec("SELECT * FROM admin WHERE password = '"+driver_admin_password+"'");

   if(query12.next()==true){

    QSqlQuery qry12;
    qry12.prepare("delete from Driver_info where email = '"+driver_delete_email+"'");
    if(qry12.exec()){
            QMessageBox :: information(this,"Delete Info.","Driver Deleted");
    }
   }
   ui->driver_delete_email_input->clear();
   ui->admin_pass_input->clear();
}


void MainWindow::on_bookprofile_button_clicked()
{
   QSqlQueryModel * modal = new QSqlQueryModel (ui->tableView_for_booking);
   modal-> setQuery(QString ("select seat,user,des_from,des_to,des_date,confirm,payment from seat"));
   modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Seat"));
   modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Email"));
   modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Destination From"));
   modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Destination To"));
   modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Destination Date"));
   modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Confirm"));
   modal->setHeaderData(6, Qt::Horizontal, QObject::tr("Payment"));


   ui->tableView_for_booking-> setModel(modal);
}





void MainWindow::on_A1_clicked()
{
   QString currentStyle1 = ui->A1->styleSheet();
   if (currentStyle1.contains("background-color: red;")) {
    return;
   }
   QString currentStyle2 = ui->A1->styleSheet();
   if (currentStyle2.contains("background-color: yellow;")) {
    return;
   }

   if (A1Flag == 1) {

    ui->A1->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "A1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();


    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    A1Flag = 0;
   }
   else {
    // Change the button color to blue
    ui->A1->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "A1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    A1Flag = 1;
   }
}







void MainWindow::on_admin_panel_back_button_clicked()
{
    ui->first_page->setCurrentIndex(6);
}


void MainWindow::on_admin_panel__login_back_button_clicked()
{
    ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_A2_clicked()
{
    QString currentStyle1 = ui->A2->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->A2->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (A2Flag == 1) {

    ui->A2->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "A2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();


    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");
    A2Flag = 0;
    }
    else {
    // Change the button color to blue
    ui->A2->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "A2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    A2Flag = 1;
    }
}


void MainWindow::on_A3_clicked()
{
    QString currentStyle1 = ui->A3->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->A3->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (A3Flag == 1) {

    ui->A3->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "A3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();
    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    A3Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->A3->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "A3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    A3Flag = 1;
    }
}


void MainWindow::on_B1_clicked()
{
    QString currentStyle1 = ui->B1->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->B1->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (B1Flag == 1) {

    ui->B1->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "B1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();
    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    B1Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->B1->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "B1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    B1Flag = 1;
    }
}


void MainWindow::on_B2_clicked()
{
    QString currentStyle1 = ui->B2->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->B2->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (B2Flag == 1) {

    ui->B2->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "B2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();
    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    B2Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->B2->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "B2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    B2Flag = 1;
    }
}


void MainWindow::on_B3_clicked()
{
    QString currentStyle1 = ui->B3->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->B3->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (B3Flag == 1) {

    ui->B3->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "B3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    B3Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->B3->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "B3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    B3Flag = 1;
    }
}


void MainWindow::on_C1_clicked()
{
    QString currentStyle1 = ui->C1->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->C1->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (C1Flag == 1) {

    ui->C1->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "C1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();
    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    C1Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->C1->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "C1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    C1Flag = 1;
    }
}


void MainWindow::on_C2_clicked()
{
    QString currentStyle1 = ui->C2->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->C2->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (C2Flag == 1) {

    ui->C2->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "C2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    C2Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->C2->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "C2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    C2Flag = 1;
    }
}


void MainWindow::on_C3_clicked()
{
    QString currentStyle1 = ui->C3->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->C3->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (C3Flag == 1) {

    ui->C3->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "C3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    C3Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->C3->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "C3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    C3Flag = 1;
    }
}


void MainWindow::on_D1_clicked()
{
    QString currentStyle1 = ui->D1->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->D1->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (D1Flag == 1) {

    ui->D1->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "D1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();
    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    D1Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->D1->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "D1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    D1Flag = 1;
    }
}


void MainWindow::on_D2_clicked()
{
    QString currentStyle1 = ui->D2->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->D2->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (D2Flag == 1) {

    ui->D2->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "D2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();
    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    D2Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->D2->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "D2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    D2Flag = 1;
    }
}


void MainWindow::on_D3_clicked()
{
    QString currentStyle1 = ui->D3->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->D3->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (D3Flag == 1) {

    ui->D3->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "D3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    D3Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->D3->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "D3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    D3Flag = 1;
    }
}


void MainWindow::on_E1_clicked()
{
    QString currentStyle1 = ui->E1->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->E1->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (E1Flag == 1) {

    ui->E1->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "E1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    E1Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->E1->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "E1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    E1Flag = 1;
    }
}


void MainWindow::on_E2_clicked()
{
    QString currentStyle1 = ui->E2->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->E2->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (E2Flag == 1) {

    ui->E2->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "E2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    E2Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->E2->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "E2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
    query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    E2Flag = 1;
    }
}


void MainWindow::on_E3_clicked()
{
    QString currentStyle1 = ui->E3->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->E3->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (E3Flag == 1) {

    ui->E3->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "E3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");
    E3Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->E3->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "E3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    E3Flag = 1;
    }
}


void MainWindow::on_F1_clicked()
{
    QString currentStyle1 = ui->F1->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->F1->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (F1Flag == 1) {

    ui->F1->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "F1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");
    F1Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->F1->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "F1";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    F1Flag = 1;
    }
}


void MainWindow::on_F2_clicked()
{
    QString currentStyle1 = ui->F2->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->F2->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (F2Flag == 1) {

    ui->F2->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "F2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();

QString des_date = ui->date_label->text();
    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    F2Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->F2->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "F2";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    F2Flag = 1;
    }
}


void MainWindow::on_F3_clicked()
{
    QString currentStyle1 = ui->F3->styleSheet();
    if (currentStyle1.contains("background-color: red;")) {
    return;
    }
    QString currentStyle2 = ui->F3->styleSheet();
    if (currentStyle2.contains("background-color: yellow;")) {
    return;
    }

    if (F3Flag == 1) {

    ui->F3->setStyleSheet("background-color: rgb(255, 255, 255);");


    // Remove data from the database
    QString seat = "F3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QSqlQuery query8;
    // query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "'");

    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
QString des_date = ui->date_label->text();

    query8.exec("DELETE FROM seat WHERE seat='" + seat + "' AND user='" + user + "' AND des_from='" + des_from + "' AND des_to='" + des_to + "' AND confirm='"+confirm+"' AND des_date='" + des_date + "'");

    F3Flag = 0;
    }
    else {
    // Change the button color to blue.
    ui->F3->setStyleSheet("background-color: rgb(85, 255, 255);");

    // Insert data into the database
    QString seat = "F3";
    QString confirm = "0";
    QString user = ui->email_label->text();  // Get the user's email from the label
    QString des_from = ui->from_label->text();
    QString des_to = ui->to_label->text();
    QString des_date = ui->date_label->text();
    QSqlQuery query8;
    //query8.exec("INSERT INTO seat (seat, user) VALUES('" + seat + "', '" + user + "')");
     query8.exec("INSERT INTO seat (seat, user, des_from, des_to,confirm,des_date) VALUES ('" + seat + "', '" + user + "', '" + des_from + "', '" + des_to + "', '" + confirm + "', '" + des_date + "')");
    F3Flag = 1;
    }
}


void MainWindow::on_admin_driver_back_button_clicked()
{
    ui->first_page->setCurrentIndex(7);
}


void MainWindow::on_Seat_selection_confirm_button_clicked()
{
    QString emailLabelValue = ui->email_label->text();
    QSqlQuery query20;
    query20.prepare("SELECT COUNT(*) FROM seat WHERE user = :emailLabelValue");
    query20.bindValue(":emailLabelValue", emailLabelValue);

    if (query20.exec()) {
    if (query20.next()) {
             count = query20.value(0).toInt();

            if (count > 4) {
                QMessageBox::information(this, "Count Info", "Sir can't choose more than 4 seats");
            } else if(count < 1)
            {
                QMessageBox::information(this, "Count Info", "Sir You have to choose at least One seat");
            }
            else if(count >= 1 && count <= 4){

                QSqlQuery confirmQuery;
                confirmQuery.exec("SELECT seat, confirm FROM seat");
                while (confirmQuery.next()) {
                QString confirmedSeat = confirmQuery.value(0).toString();
                int confirmValue = confirmQuery.value(1).toInt();
                //forA1seat;
                if (confirmValue == 1) {
                    // Seat is confirmed, set background color to red
                    if (confirmedSeat == "A1") {
                        ui->A1->setStyleSheet("background-color: red;");
                    }
                    // Add similar statements for other confirmed seats
                } else {
                    if (confirmedSeat == "A1") {
                        ui->A1->setStyleSheet("background-color: yellow;");
                    }
                }
                //forA2seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "A2") {
                        ui->A2->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "A2") {
                        ui->A2->setStyleSheet("background-color: yellow;");
                    }
                }

                //forA3seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "A3") {
                        ui->A3->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "A3") {
                        ui->A3->setStyleSheet("background-color: yellow;");
                    }
                }

                //forB1seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "B1") {
                        ui->B1->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "B1") {
                        ui->B1->setStyleSheet("background-color: yellow;");
                    }
                }

                //forB2seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "B2") {
                        ui->B2->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "B2") {
                        ui->B2->setStyleSheet("background-color: yellow;");
                    }
                }

                //forB3seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "B3") {
                        ui->B3->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "B3") {
                        ui->B3->setStyleSheet("background-color: yellow;");
                    }
                }

                //forC1seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "C1") {
                        ui->C1->setStyleSheet("background-color: red;");
                    }
                } else {
                    // Seat is not confirmed, set background color to yellow
                    if (confirmedSeat == "C1") {
                        ui->C1->setStyleSheet("background-color: yellow;");
                    }
                }

                //forC2seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "C2") {
                        ui->C2->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "C2") {
                        ui->C2->setStyleSheet("background-color: yellow;");
                    }
                }

                //forC3seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "C3") {
                        ui->C3->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "C3") {
                        ui->C3->setStyleSheet("background-color: yellow;");
                    }
                }

                //forD1seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "D1") {
                        ui->D1->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "D1") {
                        ui->D1->setStyleSheet("background-color: yellow;");
                    }
                }

                //forD2seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "D2") {
                        ui->D2->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "D2") {
                        ui->D2->setStyleSheet("background-color: yellow;");
                    }
                }

                //forD3seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "D3") {
                        ui->D3->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "D3") {
                        ui->D3->setStyleSheet("background-color: yellow;");
                    }
                }

                //forE1seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "E1") {
                        ui->E1->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "E1") {
                        ui->E1->setStyleSheet("background-color: yellow;");
                    }
                }

                //forE2seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "E2") {
                        ui->E2->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "E2") {
                        ui->E2->setStyleSheet("background-color: yellow;");
                    }
                }

                //forE3seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "E3") {
                        ui->E3->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "E3") {
                        ui->E3->setStyleSheet("background-color: yellow;");
                    }
                }

                //forF1seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "F1") {
                        ui->F1->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "F1") {
                        ui->F1->setStyleSheet("background-color: yellow;");
                    }
                }

                //forF2seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "F2") {
                        ui->F2->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "F2") {
                        ui->F2->setStyleSheet("background-color: yellow;");
                    }
                }

                //forF3seat
                if (confirmValue == 1) {
                    if (confirmedSeat == "F3") {
                        ui->F3->setStyleSheet("background-color: red;");
                    }
                } else {
                    if (confirmedSeat == "F3") {
                        ui->F3->setStyleSheet("background-color: yellow;");
                    }
                }


    }

    QString user = ui->email_label->text();
    QSqlQuery query;

    query.prepare("SELECT seat FROM seat WHERE user = :user");
    query.bindValue(":user", user);

    if (query.exec()) {
        QString allSeats;
        while (query.next()) {
                    QString seat = query.value(0).toString();
                    allSeats += "" + seat + " ";
                }

                ui->seat_label_2->setText(allSeats);
    } else {
            qDebug() << "Query execution failed: " << query.lastError().text();
    }

        }
    }
    } else {
    QMessageBox::warning(this, "Count Info", "Query Failed: " + query20.lastError().text());
    }
    int total=count*1600;

    ui->total_amount_label->setText(QString::number(total));
    ui->invoice_paid_label->setText(QString::number(total));
    ui->Total_amount_label->setText(QString::number(total));
    ui->Total_seats_label->setText(QString::number(count));

}










void MainWindow::on_job_apply_2_clicked()
{
    ui->first_page->setCurrentIndex(15);
}


void MainWindow::on_proceed_button_passenger_2_clicked()
{
     ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_paymenT_submit_button_clicked()
{
     QString Trx_email = ui->bkash_email->text();
     QString Trx_num = ui->bkash_trx->text();

     //Trx_num is available or not in Trx_id table.
     QSqlQuery trxQuery;
     trxQuery.prepare("SELECT * FROM Trx_id WHERE trx_num = :trx_num");
     trxQuery.bindValue(":trx_num", Trx_num);

     if (trxQuery.exec() && trxQuery.next()) {

    QSqlQuery qry6;
    qry6.prepare("update seat set payment = 'Paid' where user = :user_email");
    qry6.bindValue(":user_email", Trx_email);
    //if transaction id found in the database.
    if (qry6.exec() ) {
            QMessageBox::information(this, "Payment Success", "Payment Successfull.");
            ui->first_page->setCurrentIndex(17);
    } else {
            QMessageBox::critical(this, "Payment Error", "Failed to update payment status.");
    }


     }



     else {
    // Trx_num not found in Trx_info table
    QMessageBox::warning(this, "Payment Error", "Transaction number not found.");
     }

     ui->bkash_email->clear();
     ui->bkash_trx->clear();

}




void MainWindow::on_invoice_back_button_clicked()
{
    ui->first_page->setCurrentIndex(16);
}





void MainWindow::on_admin_display_logout_button_clicked()
{
    ui->first_page->setCurrentIndex(0);
}





void MainWindow::on_seat_info_clicked()
{
     ui->first_page->setCurrentIndex(16);
}


void MainWindow::on_bus_sel_back_btn_3_clicked()
{
     ui->first_page->setCurrentIndex(17);
}


void MainWindow::on_Download_refund_button_clicked()
{
    ui->first_page->setCurrentIndex(15);
}





void MainWindow::on_Home_page_button_4_clicked()
{
     ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_on_complain_done_button_clicked()
{
     QString take_complain = ui->take_complain_input->text();


     QSqlQuery query33;
     query33.exec("INSERT INTO customerComplain (complain) VALUES('"+take_complain+"')");

     QMessageBox :: information(this,"Complain Info.","Thank You for your complain.");
     ui->take_complain_input->clear();
}


void MainWindow::on_download_ticket_button_clicked()
{
    ui->first_page->setCurrentIndex(16);
}


void MainWindow::on_home_page_button_clicked()
{
    ui->first_page->setCurrentIndex(0);
}


void MainWindow::on_refun_button_clicked()
{

}


void MainWindow::on_download_ticket_back_button_clicked()
{
    ui->first_page->setCurrentIndex(15);
}


void MainWindow::on_download_ticket_button_2_clicked()
{


    email = ui->downlod_ticket_email_input->text();
    password = ui->downlod_ticket_password_input->text();

    if (email.isEmpty() || password.isEmpty()) {
    QMessageBox::warning(this, "Login", "Email and password cannot be empty");
    } else {
    QSqlQuery q1;
    q1.exec("SELECT * FROM customer_info WHERE email='" + email + "' AND password='" + password + "'");
    if (q1.next()) {
            QMessageBox::information(this, "Log In", "Successfully Logged In");

            ui->invoice_name_label->setText(q1.value(0).toString());
            ui->invoice_email_label->setText(q1.value(1).toString());
            ui->invoice_mobile_label->setText(q1.value(3).toString());
            //ui->invoice_mobile_label->setText(q1.value(0).toString());

            QString user = q1.value(1).toString();

            QSqlQuery query;
            query.prepare("SELECT * FROM seat WHERE user = :user AND confirm = 1");
            query.bindValue(":user", user);

            if (query.exec()) {
    QString allSeats, journey_date, paid, journey_from, journey_to;

    while (query.next()) {
            QString seat = query.value(0).toString();
            QString des_date = query.value(5).toString();
            QString payment = query.value(6).toString();
            QString des_from = query.value(2).toString();
            QString des_to = query.value(3).toString();
            allSeats += "" + seat + " ";
            journey_date = "" + des_date + " ";
            paid = "" + payment + " ";
            journey_from = "" + des_from + " ";
            journey_to = "" + des_to + " ";
    }

    ui->invoice_seat_label->setText(allSeats);
    ui->invoice_date_label->setText(journey_date);
    ui->invoice_paid_label->setText(paid);
    ui->invoice_from_label->setText(journey_from);
    ui->invoice_to_label->setText(journey_to);

    ui->first_page->setCurrentIndex(13);
            }
    }
    }
    ui->downlod_ticket_email_input->clear();
    ui->downlod_ticket_password_input->clear();

}





void MainWindow::on_Trx_back_button_clicked()
{
    ui->first_page->setCurrentIndex(5);
}


void MainWindow::on_About_us_button_clicked()
{
    ui->first_page->setCurrentIndex(14);
}

