#ifndef selectorWindow_h
#define selectorWindow_h

#include <QDialog>

#include <string>

#include "backend/container/block/blockDefs.h"

namespace Ui {
	class Selector;
};

class SelectorWindow : public QDialog {
	Q_OBJECT
public:
	SelectorWindow(QWidget* parent = nullptr);
	~SelectorWindow();

private:
	void updateSelectedBlock();
	void updateSelectedTool();

	Ui::Selector* ui;

signals:
	void selectedBlockChange(BlockType blockType);
	void selectedToolChange(std::string tool);
};

#endif /* selectorWindow_h */
