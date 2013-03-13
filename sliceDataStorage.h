#ifndef SLICE_DATA_STORAGE_H
#define SLICE_DATA_STORAGE_H

#include <vector>
using std::vector;
#include "utils/intpoint.h"
using ClipperLib::Polygons;

/*
SliceData
+ Layers[]
  + LayerParts[]
    + OutlinePolygons[]
    + Insets[]
      + Polygons[]
    + SkinPolygons[]
*/

class SliceLayerPart
{
public:
    AABB boundaryBox;
    Polygons outline;
    vector<Polygons> insets;
    Polygons skinOutline;
    Polygons sparseOutline;
    int bridgeAngle;
};

class SliceLayer
{
public:
    vector<SliceLayerPart> parts;
};

class SliceDataStorage
{
public:
    Point3 modelSize;
    Polygons skirt;
    vector<SliceLayer> layers;
};

#endif//SLICE_DATA_STORAGE_H
