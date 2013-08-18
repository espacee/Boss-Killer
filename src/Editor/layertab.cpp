#include "Editor/layertab.h"

LayerTab::LayerTab(QWidget *parent, TileMap* mapP)
{
    map = mapP;
    setParent(parent);
    resize(parent->size());

    addLayerButton = new QPushButton("+",this);
    connect(addLayerButton, SIGNAL(clicked()), this, SLOT(addLayerButtonClicked()));

    removeLayerButton = new QPushButton("-",this);
    connect(removeLayerButton, SIGNAL(clicked()), this, SLOT(removeLayerButtonClicked()));

    layerScrollArea = new QScrollArea(this);
    layerScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    layerScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    pan = new QWidget(this);
    layerScrollArea->setWidget(pan);
    pan->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    nbLayers = 0;
    currentLayer = 0;
    layerWidgetHeigth = 50;
    offset = 1;
    layerID=0;
}

void LayerTab::addLayer()
{
    int newLayer;

    if(nbLayers==0)
    {
        nbLayers=1;
        layers.push_back(new LayerWidget("Layer "+QString::number(layerID),pan));
        newLayer = 0;
    }
    else
    {
        nbLayers++;
        layers.insert(currentLayer+1, new LayerWidget("Layer "+QString::number(layerID),pan));

        newLayer = currentLayer+1;
    }
    layerID++;

    selectLayer(newLayer);

    connect(layers[currentLayer],SIGNAL(selected(int)),this,SLOT(selectLayer(int)));

    reorder();
}

void LayerTab::popLayer()
{

}

void LayerTab::reorder()
{
    pan->setFixedHeight(nbLayers*(layerWidgetHeigth+offset));

    for(int i=0;i<nbLayers;i++)
    {
        layers[i]->resize(pan->width(),layerWidgetHeigth);
        layers[i]->move(0, i*(layerWidgetHeigth+offset));
        layers[i]->show();
        layers[i]->setIndex(i);
    }
}

void LayerTab::resizeEvent(QResizeEvent *e)
{
    e->ignore();
    addLayerButton->setGeometry(width()-82,height()-42, 40,40);
    removeLayerButton->setGeometry(width()-42,height()-42, 40,40);
    layerScrollArea->move(4,4); layerScrollArea->resize(width()-8, height()-48);

    pan->setFixedWidth(layerScrollArea->width()-layerScrollArea->verticalScrollBar()->width());
}

void LayerTab::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}

void LayerTab::addLayerButtonClicked()
{
    addLayer();
}

void LayerTab::removeLayerButtonClicked()
{

}

void LayerTab::selectLayer(int layer)
{
    if(layer>=0 && layer<nbLayers)
    {
        layers[currentLayer]->unsetCurrent();

        currentLayer = layer;

        layers[currentLayer]->setCurrent();
    }
}