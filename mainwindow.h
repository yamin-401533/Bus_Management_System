#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_user_login_button_clicked();

    void on_signup_button_clicked();

    void on_user_button_clicked();

    void on_search_button_2_clicked();

    void on_View_seat_btn_clicked();

    void on_next_button_clicked();

    void on_proceed_button_passenger_clicked();

    void on_purchase_button_clicked();

    void on_admin_button_clicked();

    void on_admin_login_button_clicked();

    void on_Admin_panel_next_clicked();

    void on_Driver_next_clicked();

    void on_des_back_btn_clicked();

    void on_signlog_back_clicked();

    void on_bus_sel_back_btn_clicked();

    void on_from_combo_box_currentTextChanged(const QString &arg1);

    void on_to_combo_box_currentTextChanged(const QString &arg1);

    void on_date_combo_box_userDateChanged(const QDate &date);

    void on_date_combo_box_dateChanged(const QDate &date);

    void on_payment_back_clicked();

    void on_seat_selec_back_btn_clicked();





    void on_profile_button_clicked();

    void on_complain_box_clicked();

    void on_confirm_seatbooking_btn_clicked();

    void on_job_apply_clicked();

    void on_Home_page_button_clicked();

    void on_Home_page_button_2_clicked();

    void on_Home_page_button_3_clicked();

    void on_Apply_job_button_clicked();

    void on_Driver_add_submit_button_clicked();

    void on_admin_display_back_button_clicked();

    void on_Driver_delete_button_clicked();

    void on_bookprofile_button_clicked();



    void on_A1_clicked();

    void on_admin_panel_back_button_clicked();

    void on_admin_panel__login_back_button_clicked();

    void on_A2_clicked();

    void on_A3_clicked();

    void on_B1_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

    void on_C1_clicked();

    void on_C2_clicked();

    void on_C3_clicked();

    void on_D1_clicked();

    void on_D2_clicked();

    void on_D3_clicked();

    void on_E1_clicked();

    void on_E2_clicked();

    void on_E3_clicked();

    void on_F1_clicked();

    void on_F2_clicked();

    void on_F3_clicked();

    void on_admin_driver_back_button_clicked();

    void on_Seat_selection_confirm_button_clicked();



    void on_job_apply_2_clicked();

    void on_proceed_button_passenger_2_clicked();

    void on_paymenT_submit_button_clicked();

    void on_invoice_back_button_clicked();



    void on_admin_display_logout_button_clicked();



    void on_seat_info_clicked();

    void on_bus_sel_back_btn_3_clicked();

    void on_Download_refund_button_clicked();



    void on_Home_page_button_4_clicked();

    void on_on_complain_done_button_clicked();

    void on_download_ticket_button_clicked();

    void on_home_page_button_clicked();

    void on_refun_button_clicked();

    void on_download_ticket_back_button_clicked();

    void on_download_ticket_button_2_clicked();



    void on_Trx_back_button_clicked();





    void on_About_us_button_clicked();

private:
    Ui::MainWindow *ui;
    QString name_sign, email_sign, password_sign, contact_sign, confirm_pass_sign;
    QString job_driver_name,job_driver_email,job_driver_contact,job_driver_address,job_driver_experience;
    QString add_driver_name,add_driver_email,add_driver_contact;
    QString driver_delete_email,driver_admin_password;
    QString email, password;
    QString admin_email, admin_password;
    QString confirm_email,confirm_to_1;
    QString Trx_email,Trx_num;
    QString user;
    QString Q1,Q2;
    int A1Flag = 0;
    int A2Flag = 0;
    int A3Flag = 0;
    int B1Flag = 0;
    int B2Flag = 0;
    int B3Flag = 0;
    int C1Flag = 0;
    int C2Flag = 0;
    int C3Flag = 0;
    int D1Flag = 0;
    int D2Flag = 0;
    int D3Flag = 0;
    int E1Flag = 0;
    int E2Flag = 0;
    int E3Flag = 0;
    int F1Flag = 0;
    int F2Flag = 0;
    int F3Flag = 0;
    int count;

    //int numof_seat;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
