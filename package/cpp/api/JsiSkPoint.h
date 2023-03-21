#pragma once

#include <memory>
#include <utility>

#include <jsi/jsi.h>

#include "JsiSkHostObjects.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

#include "SkPoint.h"
#include "SkPoint3.h"

#pragma clang diagnostic pop

namespace RNSkia {

namespace jsi = facebook::jsi;

class JsiSkPoint : public JsiSkWrappingSharedPtrHostObject<SkPoint> {
public:
  JSI_PROPERTY_GET(x) { return static_cast<double>(getObject()->x()); }

  JSI_PROPERTY_GET(y) { return static_cast<double>(getObject()->y()); }

  JSI_EXPORT_PROPERTY_GETTERS(JSI_EXPORT_PROP_GET(JsiSkPoint, x),
                              JSI_EXPORT_PROP_GET(JsiSkPoint, y))

  JsiSkPoint(std::shared_ptr<RNSkPlatformContext> context, const SkPoint &point)
      : JsiSkWrappingSharedPtrHostObject<SkPoint>(
            std::move(context), std::make_shared<SkPoint>(point)) {}

  /**
  Returns the underlying object from a host object of this type
 */
  static std::shared_ptr<SkPoint> fromValue(jsi::Runtime &runtime,
                                            const jsi::Value &obj) {
    const auto &object = obj.asObject(runtime);
    if (object.isHostObject(runtime)) {
      return object.asHostObject<JsiSkPoint>(runtime)->getObject();
    } else {
      auto x = object.getProperty(runtime, "x").asNumber();
      auto y = object.getProperty(runtime, "y").asNumber();
      return std::make_shared<SkPoint>(SkPoint::Make(x, y));
    }
  }

  /**
  Returns the jsi object from a host object of this type
 */
  static jsi::Value toValue(jsi::Runtime &runtime,
                            std::shared_ptr<RNSkPlatformContext> context,
                            const SkPoint &point) {
    return jsi::Object::createFromHostObject(
        runtime, std::make_shared<JsiSkPoint>(std::move(context), point));
  }

  /**
   * Creates the function for construction a new instance of the SkPoint
   * wrapper
   * @param context platform context
   * @return A function for creating a new host object wrapper for the SkPoint
   * class
   */
  static const jsi::HostFunctionType
  createCtor(std::shared_ptr<RNSkPlatformContext> context) {
    return JSI_HOST_FUNCTION_LAMBDA {
      auto point =
          SkPoint::Make(arguments[0].asNumber(), arguments[1].asNumber());

      // Return the newly constructed object
      return jsi::Object::createFromHostObject(
          runtime,
          std::make_shared<JsiSkPoint>(std::move(context), std::move(point)));
    };
  }
};

class JsiSkPoint3 : public JsiSkWrappingSharedPtrHostObject<SkPoint3> {
public:
  JSI_PROPERTY_GET(x) { return static_cast<double>(getObject()->x()); }

  JSI_PROPERTY_GET(y) { return static_cast<double>(getObject()->y()); }

  JSI_PROPERTY_GET(z) { return static_cast<double>(getObject()->z()); }

  JSI_EXPORT_PROPERTY_GETTERS(JSI_EXPORT_PROP_GET(JsiSkPoint3, x),
                              JSI_EXPORT_PROP_GET(JsiSkPoint3, y),
                              JSI_EXPORT_PROP_GET(JsiSkPoint3, z))

  JsiSkPoint3(std::shared_ptr<RNSkPlatformContext> context,
              const SkPoint3 &point)
      : JsiSkWrappingSharedPtrHostObject<SkPoint3>(
            std::move(context), std::make_shared<SkPoint3>(point)) {}

  /**
  Returns the underlying object from a host object of this type
 */
  static std::shared_ptr<SkPoint3> fromValue(jsi::Runtime &runtime,
                                             const jsi::Value &obj) {
    const auto &object = obj.asObject(runtime);
    if (object.isHostObject(runtime)) {
      return object.asHostObject<JsiSkPoint3>(runtime)->getObject();
    } else {
      auto x = object.getProperty(runtime, "x").asNumber();
      auto y = object.getProperty(runtime, "y").asNumber();
      auto z = object.getProperty(runtime, "z").asNumber();
      return std::make_shared<SkPoint3>(SkPoint3::Make(x, y, z));
    }
  }

  /**
  Returns the jsi object from a host object of this type
 */
  static jsi::Value toValue(jsi::Runtime &runtime,
                            std::shared_ptr<RNSkPlatformContext> context,
                            const SkPoint3 &point) {
    return jsi::Object::createFromHostObject(
        runtime, std::make_shared<JsiSkPoint3>(std::move(context), point));
  }

  /**
   * Creates the function for construction a new instance of the SkPoint
   * wrapper
   * @param context platform context
   * @return A function for creating a new host object wrapper for the SkPoint
   * class
   */
  static const jsi::HostFunctionType
  createCtor(std::shared_ptr<RNSkPlatformContext> context) {
    return JSI_HOST_FUNCTION_LAMBDA {
      auto point =
          SkPoint3::Make(arguments[0].asNumber(), arguments[1].asNumber(),
                         arguments[2].asNumber());

      // Return the newly constructed object
      return jsi::Object::createFromHostObject(
          runtime,
          std::make_shared<JsiSkPoint3>(std::move(context), std::move(point)));
    };
  }
};
} // namespace RNSkia
