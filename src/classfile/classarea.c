/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

static getAttribues(char * attribute_name_index, byte * bytes)
{
  Reader * reader = newReader(bytes);
          var attribute = { attribute_name_index: attribute_name_index };


        var item = classImage.constant_pool[attribute_name_index];


        switch(item.tag) {

            case TAGS.CONSTANT_Long:
            case TAGS.CONSTANT_Float:
            case TAGS.CONSTANT_Double:
            case TAGS.CONSTANT_Integer:
            case TAGS.CONSTANT_String:
                attribute.type = ATTRIBUTE_TYPES.ConstantValue;
                attribute.constantvalue_index = reader.read16();
                return attribute;


            case TAGS.CONSTANT_Utf8:

                switch(item.bytes) {

                    case ATTRIBUTE_TYPES.Code:
                        attribute.type = ATTRIBUTE_TYPES.Code;
                        attribute.max_stack = reader.read16();
                        attribute.max_locals = reader.read16();
                        var code_length = reader.read32();
                        attribute.code = reader.readBytes(code_length);

                        var exception_table_length = reader.read16();
                        attribute.exception_table = [];
                        for(var i=0; i<exception_table_length; i++) {
                            var start_pc = reader.read16();
                            var end_pc = reader.read16();
                            var handler_pc= reader.read16();
                            var catch_type = reader.read16();
                            attribute.exception_table.push({start_pc:start_pc,end_pc:end_pc,handler_pc:handler_pc,catch_type:catch_type });
                        }

                        var attributes_count = reader.read16();
                        attribute.attributes = [];
                        for(var i=0; i<attributes_count; i++) {
                            var attribute_name_index = reader.read16();
                            var attribute_length = reader.read32();
                            var info = reader.readBytes(attribute_length);
                            attribute.attributes.push({ attribute_name_index: attribute_name_index, attribute_length: attribute_length, info: info });
                        }
                        return attribute;

                    case ATTRIBUTE_TYPES.SourceFile:
                        attribute.type = ATTRIBUTE_TYPES.SourceFile;
                        attribute.sourcefile_index = reader.read16();
                        return attribute;

                    case ATTRIBUTE_TYPES.Exceptions:
                        attribute.type = ATTRIBUTE_TYPES.Exceptions;
                        var number_of_exceptions = reader.read16();
                        attribute.exception_index_table = [];
                        for(var i=0; i<number_of_exceptions; i++) {
                            attribute.exception_index_table.push(reader.read16());
                        }
                        return attribute;

                    case ATTRIBUTE_TYPES.InnerClasses:
                        attribute.type = ATTRIBUTE_TYPES.InnerClasses;
                        var number_of_classes = reader.read16();
                        attribute.classes = [];
                        for(var i=0; i<number_of_classes; i++) {
                            var inner = {};
                            inner.inner_class_info_index = reader.read16();
                            inner.outer_class_info_index = reader.read16();
                            inner.inner_name_index = reader.read16();
                            inner.inner_class_access_flags = reader.read16();
                            attribute.classes.push(inner);
                        }
                        return attribute;

                    default:
                        throw new Error("This attribute type is not supported yet. [" + JSON.stringify(item) + "]");
                }

            default:
                throw new Error("This attribute type is not supported yet. [" + JSON.stringify(item) + "]");
        }
    };

}

Map * getClassImage(byte* classBytes)
{

}