#include "LayerStrategy.h"
#include "MapView.h"

LayerStrategy::LayerStrategy(MapView *mapView)
{
	this->mapView=mapView;
}

void LayerStrategy::addAllowedTool(PaintStrategy *tool)
{
	if (!allowedTools.contains(tool))
		allowedTools.append(tool);
}

void LayerStrategy::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
	PaintStrategy * current = mapView->getCurrentPaint();
	foreach(PaintStrategy * paint, allowedTools)
		if (paint==current)
			current->mousePressEvent(mouseEvent);
}

void LayerStrategy::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
	PaintStrategy * current = mapView->getCurrentPaint();
	foreach(PaintStrategy * paint, allowedTools)
		if (paint==current)
			current->mouseMoveEvent(mouseEvent);
}
void LayerStrategy::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
	PaintStrategy * current = mapView->getCurrentPaint();
	foreach(PaintStrategy * paint, allowedTools)
		if (paint==current)
			current->mouseReleaseEvent(mouseEvent);
}
void LayerStrategy::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
{
	PaintStrategy * current = mapView->getCurrentPaint();
	foreach(PaintStrategy * paint, allowedTools)
		if (paint==current)
			current->contextMenuEvent(contextMenuEvent);
}
