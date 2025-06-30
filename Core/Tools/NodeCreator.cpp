#include "NodeCreator.h"
#include "NetworkMap.h"
#include "Host.h"
#include "TextLabel.h"
#include "SdnController.h"

NodeCreator::NodeCreator(NetworkMap *map) :
    map(map)
{
    setSdnControllerCreation();
}

void NodeCreator::handleMouseDown(QPoint position)
{
    createNode(map, position);
}

void NodeCreator::setSdnControllerCreation()
{
    createNode = [] (NetworkMap *map, QPoint position)
    {
        map->addSdnController(new SdnController(position));
    };
}

void NodeCreator::setSwitchCreation()
{
    createNode = [] (NetworkMap *map, QPoint position)
    {
        int num = map->getSwitches().size() + 1;
        Switch* sw = new Switch(position);
        sw->setup(num);
        sw->setName(QString("s%1").arg(num));
        map->addSwitch(sw);
    };
}

void NodeCreator::setHostCreation()
{
    createNode = [] (NetworkMap *map, QPoint position)
    {
        map->addHost(new Host(position));
    };
}

void NodeCreator::setTextLabelCreation()
{
    createNode = [] (NetworkMap *map, QPoint position)
    {
        map->addTextLabel(new TextLabel(position, true));
    };
}
