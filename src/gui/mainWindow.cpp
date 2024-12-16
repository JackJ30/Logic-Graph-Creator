#include <QHBoxLayout>
#include <QTreeView>

#include "gridGUI/logicGridWindow.h"
#include "resouces/ui_mainWindow.h"
#include "mainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle(tr("Example Window"));

    BlockContainer* blockContainer = new BlockContainer();

    blockContainer->tryInsertBlock(Position(0, 0), ZERO, AND);
    blockContainer->tryInsertBlock(Position(2, 0), ZERO, AND);
    blockContainer->tryCreateConnection(Position(0, 0), Position(2, 0));

    LogicGridWindow* logicGridWindow = new LogicGridWindow(this);
    logicGridWindow->loadTileMap(":/gui/resources/logicTiles.png");
    logicGridWindow->setBlockContainer(blockContainer);
    logicGridWindow->setSelector(ui->selectorTreeWidget);

    QVBoxLayout* layout = new QVBoxLayout(ui->gridWindow);
    layout->addWidget(logicGridWindow);
}
