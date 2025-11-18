#pragma once

#include <string>
#include <_common.h>

class GltfModel;

class _gltfLoader {
public:
    _gltfLoader();
    ~_gltfLoader();

    GltfModel* loadModel(const std::string& filename);
};
