#pragma once

#include <vector>
#include <memory>
#include <map>

#include <semantic/Method.h>
#include <visitors/ClassInformation.h>

class Object;

typedef std::shared_ptr<Object> Other;

class Object {
    public:
        Object(const std::string& class_name);
        virtual std::string toString();
        virtual int& GetInt();
        virtual bool& GetBool();
        virtual std::vector<Other>& GetArray();
        Method* FindMethod(const std::string& method_name);
        std::shared_ptr<Object> FindField(const std::string& field_name);
        friend Other Allocate(Type* type, const std::map<std::string, ClassInformation>& class_information, int size);
        const std::string& GetClassName() const;

private:
    std::map<std::string, Method*> methods;
    std::map<std::string, std::shared_ptr<Object>> fields;
    std::string class_name;
};
