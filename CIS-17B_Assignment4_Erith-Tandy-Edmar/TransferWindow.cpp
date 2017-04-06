#include "TransferWindow.h"

TransferWindow::TransferWindow(QWidget *parent) : QWidget(parent)
{

}

void TransferWindow::transferWin()
{
    QMessageBox::information(
        this,
        tr("Transfer Template"),
        tr("not his fault but blame tandy") );
    //"Transfer Funds" button should open a
         // dialog displaying "Account to transfer from"
          //  selection box, "Account to transfer to"
            //selection box, and a box to fill in an amount
            //to transfer. This dialog should also have an "Ok"
            //button and a "Cancel" button
    //
}
