#include "mainwindow.h"
#include <QMouseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    startPos = event->pos();
}

//void MainWindow::mouseReleaseEvent(QMouseEvent *event)
//{
//    QPoint endPos = event->pos();

//    int distance = endPos.x() - startPos.x();

//    if (qAbs(distance) > 100) {
//        if (distance > 0) {
//            // Handle right swipe
//            QMessageBox::information(this, "Swipe", "Right swipe detected.");
//        } else {
//            // Handle left swipe
//            QMessageBox::information(this, "Swipe", "Left swipe detected.");
//        }
//    }
//}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint endPos = event->pos();

    int distanceX = endPos.x() - startPos.x();
    int distanceY = endPos.y() - startPos.y();

    if (qAbs(distanceX) > 100 || qAbs(distanceY) > 100) {
        if (qAbs(distanceX) > qAbs(distanceY)) {
            if (distanceX > 0) {
                // Handle right swipe
                QMessageBox::information(this, "Swipe", "Right swipe detected.");
            } else {
                // Handle left swipe
                QMessageBox::information(this, "Swipe", "Left swipe detected.");
            }
        } else {
            if (distanceY > 0) {
                // Handle down swipe
                QMessageBox::information(this, "Swipe", "Down swipe detected.");
            } else {
                // Handle up swipe
                QMessageBox::information(this, "Swipe", "Up swipe detected.");
            }
        }
    }
}
