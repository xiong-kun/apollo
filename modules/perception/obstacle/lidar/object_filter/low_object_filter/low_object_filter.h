/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_PERCEPTION_OBSTACLE_LIDAR_OBJECT_FILTER_LOW_OBJECT_FILTER_H_
#define MODULES_PERCEPTION_OBSTACLE_LIDAR_OBJECT_FILTER_LOW_OBJECT_FILTER_H_

#include <string>
#include <vector>

#include "modules/perception/obstacle/lidar/interface/base_object_filter.h"
#include "modules/perception/lib/config_manager/config_manager.h"

namespace apollo {
namespace perception {

class LowObjectFilter : public BaseObjectFilter {
 private:
    // config params
    double object_height_threshold_ = 0.10;
    double object_position_height_threshold_ = -1.6;

 public:
    LowObjectFilter() : BaseObjectFilter() {}
    virtual ~LowObjectFilter() {}

    bool Init();

    std::string name() const {return "LowObjectFilter";}

    bool Filter(const ObjectFilterOptions& obj_filter_options,
                std::vector<ObjectPtr>* objects);

 protected:
    void FilterLowObject(
                const ObjectFilterOptions& obj_filter_options,
                std::vector<ObjectPtr>* objects);

 private:
    DISALLOW_COPY_AND_ASSIGN(LowObjectFilter);
};

// Register plugin.
REGISTER_OBJECTFILTER(LowObjectFilter);
}  // namespace perception
}  // namespace apollo
#endif // MODULES_PERCEPTION_OBSTACLE_LIDAR_OBJECT_FILTER_LOW_OBJECT_FILTER_H_ 