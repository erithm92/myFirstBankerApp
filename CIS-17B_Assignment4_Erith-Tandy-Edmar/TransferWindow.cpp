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
}
