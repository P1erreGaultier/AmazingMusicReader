#include "hometabwidget.hpp"

HomeTabWidget::HomeTabWidget(QWidget *parent) : QWidget(parent)
{
    label__.setParent(this);
    label__.setWordWrap(true);
    label__.setText(QString("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras dapibus, libero a aliquam tempor, risus magna volutpat eros, non laoreet urna risus quis leo. Aliquam rutrum erat at condimentum imperdiet. Aliquam at orci tempus, aliquam arcu eget, feugiat nibh. Pellentesque sed tristique velit. Suspendisse pharetra sem condimentum pretium tincidunt. Sed porta eros id diam scelerisque, vitae tincidunt velit cursus. Vivamus finibus, sapien tempus finibus pretium, nisi elit fringilla enim, eget dignissim eros massa varius purus. Sed et turpis ornare, molestie orci commodo, volutpat nisl. Maecenas ut erat sit amet mi laoreet congue. Aenean tincidunt mi mi, non efficitur erat varius rhoncus. Nulla fringilla nisl quis nisl lacinia tincidunt."));

    layout__.addWidget(&label__);

    this->setLayout(&layout__);
}
