bl_info = {
    "name": "CAD Refresh",
    "blender": (2, 80, 0),
    "category": "Object",
}
def register():
    print("Hello World")
def unregister():
    print("Goodbye World")
            
import bpy

# Define a custom operator class that inherits from bpy.types.Operator
class OBJECT_OT_change_material(bpy.types.Operator):
    #i want to program to, join those 

# Define a custom panel class that inherits from bpy.types.Panel
class OBJECT_PT_change_material(bpy.types.Panel):
    # Set the bl_idname, bl_label, bl_space_type and bl_region_type attributes of the panel
    bl_idname = "OBJECT_PT_change_material"
    bl_label = "Change Material"
    bl_space_type = "VIEW_3D"
    bl_region_type = "UI"
    
    # Define the draw method of the panel
    def draw(self, context):
        # Get the layout of the panel
        layout = self.layout
        
        # Add a row to the layout and add a button that calls the custom operator
        row = layout.row()
        row.operator("object.change_material", text="Change Material")

# Define a register function that registers the custom classes
def register():
    bpy.utils.register_class(OBJECT_OT_change_material)
    bpy.utils.register_class(OBJECT_PT_change_material)

# Define an unregister function that unregisters the custom classes
def unregister():
    bpy.utils.unregister_class(OBJECT_OT_change_material)
    bpy.utils.unregister_class(OBJECT_PT_change_material)

# If the script is run directly, call the register function
if __name__ == "__main__":
    register()