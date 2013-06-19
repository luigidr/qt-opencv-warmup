#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //choose the image to open
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    //read the image
    image = imread(filename.toAscii().data());

/** with HighGui (OpenCV) - open a new window by default
    //create a named image window
    namedWindow("Original Image");
    //show the image
    imshow("Original Image", image);
**/

    //with Qt - in the same window
    //prepare the image for the Qt format...

    //... change color channel ordering (from BGR in our Mat to RGB in QImage)
    cvtColor(image, image, CV_BGR2RGB);

    //Qt image
    //image.step is needed to properly show some images (due to padding byte added in the Mat creation)
    QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.step, QImage::Format_RGB888);

    //display on label
    ui->label->setPixmap(QPixmap::fromImage(img));

    //resize the label to fit the image
    ui->label->resize(ui->label->pixmap()->size());

}
