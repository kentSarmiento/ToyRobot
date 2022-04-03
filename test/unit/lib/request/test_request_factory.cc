#include "catch.hpp"
#include "request_factory.h"
#include "request_type.h"

using namespace toyrobot;

TEST_CASE("RequestFactory: Create Requests", "[RequestFactory]") {

    SECTION("Create PLACE Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, 0, "0,0,NORTH");

        REQUIRE(request->request_name() == RequestType::kPlaceRequest);
        REQUIRE(request->is_valid());
        delete request;
    }
    SECTION("Create LEFT Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kLeftRequest, 0, {});

        REQUIRE(request->request_name() == RequestType::kLeftRequest);
        REQUIRE(request->is_valid());
        delete request;
    }
    SECTION("Create RIGHT Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kRightRequest, 0, {});

        REQUIRE(request->request_name() == RequestType::kRightRequest);
        REQUIRE(request->is_valid());
        delete request;
    }
    SECTION("Create MOVE Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kMoveRequest, 0, {});

        REQUIRE(request->request_name() == RequestType::kMoveRequest);
        REQUIRE(request->is_valid());
        delete request;
    }
    SECTION("Create REPORT Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kReportRequest, 0, {});

        REQUIRE(request->request_name() == RequestType::kReportRequest);
        REQUIRE(request->is_valid());
        delete request;
    }
}