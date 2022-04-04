#include "place_request.h"
#include "object_factory.h"

namespace toyrobot {

BaseResponse* PlaceRequest::Execute(Table &table) {
    BaseResponse *response = nullptr;

    if (is_initial_request_ && table.IsCoordinatesAvailable(position_)) {
        BaseObject *object = ObjectFactory::CreateObject(object_type_, position_, facing_);
        object_id_ = table.PlaceObject(object);
        response = new PlaceResponse(object_id_);
    } else if (table.IsCoordinatesAvailable(object_id_, position_)) {
        BaseObject *object = ObjectFactory::CreateObject(object_type_, position_, facing_);
        object_id_ = table.PlaceObject(object_id_, object);
        response = new PlaceResponse(object_id_);
    }

    return response;
}

void PlaceRequest::ParseData(string data) {
    stringstream input_stream(data);
    char c;
    int x, y;

    if ((input_stream >> x) && (input_stream >> c) &&
        (input_stream >> y) && (input_stream >> c) &&
        (input_stream >> data)) {
        position_ = Coordinates(x, y);
        if (Direction::IsValidDirection(data)) {
            facing_ = Direction(data);
            is_valid_ = true;
        }
    }
}

} // namespace toyrobot