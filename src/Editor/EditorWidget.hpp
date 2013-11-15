#ifndef EDITORWIDGET_HPP
#define EDITORWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QTimer>
#include <QFileDialog>

#include "SFMLWidget.hpp"
#include "tilewidget.h"
#include "LayerTabWidget.hpp"
#include "Map/TileMap.hpp"
#include "Entities/EntityContainer.hpp"

class EditorWidget : public QWidget
{
    Q_OBJECT

public:
    EditorWidget(QWidget *parent = 0);
    ~EditorWidget();

public slots:
    void onInit();
    void onUpdate();
    void quitClicked();
    void minimizeClicked();

    void pointerToolButtonClicked();
    void arrowToolButtonClicked();
    void penToolButtonClicked();
    void randomPenToolButtonClicked();
    void patternBrushToolButtonClicked();
    void eraserToolButtonClicked();
    void fillShapeToolButtonClicked();
    void selectAreaToolButtonClicked();
    void entityToolButtonClicked();
    void objectToolButtonClicked();
    void handToolButtonClicked();
    void zoomToolButtonClicked();
    void newButtonClicked();
    void openButtonClicked();
    void saveButtonClicked();

    void resetCameraButtonClicked();
    void toggleGridButtonClicked();
    void toggleVisibleButtonClicked();

    void uncheckToolButtons();

    void tileButtonClicked();
    void tileSelected(int new_id);
    void tileSelected(QPixmap tile);

    void setCurrentLayer(int layer);

private:

    TileMap map;
    EntityContainer cont;

    QTimer timer;
    unsigned int frameTime;

    void initWindow();
    void initToolBar();
    void initTopBar();
    void initRightPanel();
    void initBotBar();
    void initCentralWidget();

    int menuBarHeight, globalPadding;
    int toolBarWidth, toolButtonSize, toolButtonPadding, toolBarTopOffset, toolSeparatorSize;
    int topBarHeight, topButtonSize;
    int rightPanelWidth;
    int botBarHeight;

    float clear_red, clear_green, clear_blue;
    bool a, b, c;

    SFMLWidget* sfmlWidget;
    sf::View camera;

    QWidget *toolBar;
    QWidget *topBar;
    QWidget *rightPanel;
    QWidget *botBar;
    QWidget *centralWidget;

    QLabel* windowIcon;
    QPushButton* minimizeButton;
    QPushButton* closeButton;
    QPushButton* newButton;
    QPushButton* openButton;
    QPushButton* saveButton;

    int tool;
    QPushButton* pointerToolButton;
    QPushButton* penToolButton;
    QPushButton* randomPenToolButton;
    QPushButton* patternBrushToolButton;
    QPushButton* eraserToolButton;
    QPushButton* fillShapeToolButton;
    QPushButton* selectAreaToolButton;
    QPushButton* arrowToolButton;
    QPushButton* entityToolButton;
    QPushButton* objectToolButton;
    QPushButton* handToolButton;
    QPushButton* zoomToolButton;

    QPushButton* resetCameraButton;
    QPushButton* toggleGridButton;
    QPushButton* toggleVisibleButton;

    TileWidget* tileWidget;
    int id;

    QPushButton* tileButton;

    LayerTabWidget* layerTab;
    bool gridEnabled;
    int currentLayer, mainLayer;

    QFileDialog* fileDialog = new QFileDialog;
    std::string filePath;

};

#endif // EDITORWIDGET_HPP
