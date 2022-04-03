#include "catch.hpp"
#include "request_handler.h"
#include "request_factory.h"
#include "request_type.h"
#include "base_request.h"
#include "base_response.h"

using namespace toyrobot;

TEST_CASE("RequestHandler: Create Requests", "[RequestHandler]") {

    SECTION("Handle PLACE Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kPlaceRequest, 0, "0,0,NORTH");
        BaseResponse *response = RequestHandler::HandleCommand(request);

        REQUIRE(request);
        REQUIRE(response);

        delete request;
        delete response;
    }
    SECTION("Handle LEFT Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kLeftRequest, 0, {});
        BaseResponse *response = RequestHandler::HandleCommand(request);

        REQUIRE(request);
        REQUIRE(response);

        delete request;
        delete response;
    }
    SECTION("Handle RIGHT Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kRightRequest, 0, {});
        BaseResponse *response = RequestHandler::HandleCommand(request);

        REQUIRE(request);
        REQUIRE(response);

        delete request;
        delete response;
    }
    SECTION("Handle MOVE Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kMoveRequest, 0, {});
        BaseResponse *response = RequestHandler::HandleCommand(request);

        REQUIRE(request);
        REQUIRE(response);

        delete request;
        delete response;
    }
    SECTION("Handle REPORT Request") {
        BaseRequest *request = RequestFactory::CreateRequest(RequestType::kReportRequest, 0, {});
        BaseResponse *response = RequestHandler::HandleCommand(request);

        REQUIRE(request);
        REQUIRE(response);

        delete request;
        delete response;
    }
}