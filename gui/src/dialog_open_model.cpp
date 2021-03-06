#include "dialog_open_model.h"
#include "ui_dialog_open_model.h"
#include <QFileDialog>
#include "new_event_dialog.h"



simbad::gui::Dialog_open_model::Dialog_open_model(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_open_model)
{
    ui->setupUi(this);
    ui->tableWidget->selectRow(0);
     ;
//    we have mistake here ->
//    this->ui->spinBox_2->setValue(3);

}

simbad::gui::Dialog_open_model::~Dialog_open_model()
{
    delete ui;
}



void simbad::gui::Dialog_open_model::on_pushButton_4_clicked()
{
    New_event_dialog my_New_event_dialog;

//save refferens to  Big_model "main model"

    my_New_event_dialog.Big_model=this->Big_model;

    my_New_event_dialog.Big_model->set_number_of_types(this->ui->spinBox_2->value());

    my_New_event_dialog.initialisation_of_New_event_dialog();





    my_New_event_dialog.setModal(true);
    my_New_event_dialog.exec();

    this->ui->tableWidget->setColumnCount(1);
    this->ui->tableWidget->setRowCount(this->Big_model->List_of_events_of_model.size());
    for(int i=0;i<this->Big_model->List_of_events_of_model.size();i++)
    {
        QString S=this->Big_model->List_of_events_of_model[i].get_name_of_event();

        QTableWidgetItem *newItem = new QTableWidgetItem(S,0);
        this->ui->tableWidget->setItem(i, 0, newItem);
    };

//changing of maximum of spin box
 this->ui->spinBox_3->setMinimum(1);
 this->ui->spinBox_3->setMaximum(this->Big_model->List_of_events_of_model.size());
}

void simbad::gui::Dialog_open_model::on_spinBox_2_valueChanged(int arg1)
{
    this->Big_model->set_number_of_types(arg1);   
}




void simbad::gui::Dialog_open_model::initialization_of_Table()
{
    this->ui->tableWidget->clear();
}

void simbad::gui::Dialog_open_model::on_spinBox_3_valueChanged(int arg1)
{
    this->ui->tableWidget->selectRow(arg1-1);
}

void simbad::gui::Dialog_open_model::on_tableWidget_clicked(const QModelIndex &index)
{
 this->ui->spinBox_3->setValue(this->ui->tableWidget->currentRow()+1);
}

void simbad::gui::Dialog_open_model::on_pushButton_3_clicked()
{
    if (this->ui->spinBox_3->value()!=0) {

        QString String_for_event = this->ui->tableWidget->currentItem()->text();
        simbad::gui::Event_of_model Event;

        Event.set_name_of_event(String_for_event);
        Event.set_code_of_event(String_for_event);
        Event.set_type_of_event(String_for_event);
        Event.set_number_of_types_for_event_of_model(this->Big_model->get_number_of_types());


        QVector<Event_of_model>::const_pointer p1 = std::remove (this->Big_model->List_of_events_of_model.begin(),
                             this->Big_model->List_of_events_of_model.end(), Event);

        this->Big_model->List_of_events_of_model.pop_back();

        this->initialization_of_Table();

        this->ui->tableWidget->setColumnCount(1);
        this->ui->tableWidget->setRowCount(this->Big_model->List_of_events_of_model.size());
        for(int i=0;i<this->Big_model->List_of_events_of_model.size();i++)
        {
            QString S=this->Big_model->List_of_events_of_model[i].get_name_of_event();

            QTableWidgetItem *newItem = new QTableWidgetItem(S,0);
            this->ui->tableWidget->setItem(i, 0, newItem);
        };

        //changing of maximum of spin box
        this->ui->spinBox_3->setMinimum(1);
        this->ui->spinBox_3->setMaximum(this->Big_model->List_of_events_of_model.size());


        if (this->Big_model->List_of_events_of_model.size()!=0){
            this->ui->tableWidget->selectRow(this->ui->spinBox_3->minimum()-1);
            this->ui->spinBox_3->setValue(this->ui->spinBox_3->minimum());
        };
    };
}

void simbad::gui::Dialog_open_model::on_pushButton_2_clicked()
{
    if (this->ui->spinBox_3->value()!=0) {
        New_event_dialog my_New_event_dialog;

    //save refferens to  Big_model "main model"

        my_New_event_dialog.Big_model=this->Big_model;

        my_New_event_dialog.Big_model->set_number_of_types(this->ui->spinBox_2->value());

        my_New_event_dialog.initialisation_of_changing_event_dialog(this->ui->spinBox_3->value()-1);

        my_New_event_dialog.setModal(true);

        my_New_event_dialog.exec();
    };
}

void simbad::gui::Dialog_open_model::on_pushButton_clicked()
{

    this->close();
}
