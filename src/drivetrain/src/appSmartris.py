#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Pose2D, Twist
from std_msgs.msg import Float32,Bool,String, Int32
from canopen_chain_node.srv import SetObject

class AppSmartris:
	def __init__(self, nodeName):
		#service and suscriber
		rospy.wait_for_service("driver/set_object")
		self.set_object = rospy.ServiceProxy("driver/set_object", SetObject)
		rospy.Subscriber("/cmd_vel", Twist, self.cmd_Callback)
		rospy.Subscriber("/Ultra", Float32, self.ultra_fault)
		rospy.Subscriber("btn_manual", Bool, self.btn_manual)
		rospy.Subscriber("btn_seguidordeLinea", Bool, self.btn_seguidordeLinea)
		rospy.Subscriber("btn_estacion1", Bool, self.btn_estacion1)
		rospy.Subscriber("btn_estacion2", Bool, self.btn_estacion2)
		rospy.Subscriber("cmd_velJoystick", Twist, self.cmd_velJoystick)
		#60FF value +: antihorario
		#60FF value -: horario

		# variables
		self.motor_cmd = 0 #velocidad LINE FOLLOWER
		self.motor_cmdc = 0 #velocidad control
		self.dist= 0 
		self.manual = 0 #activa el modo manual del sistema en el HMI
		self.seguidordeLinea = 0 #activa el modo seguidor de linea en el HMI
		self.estacion1 = 0 #indica al sistema ir a la estación 1 del alamacen de Sumitomo
		self.estacion2 = 0  #indica al sistema ir a la estacion 2 del almacen de Sumitomo
		self.velJoystickL = 0 #indica al sistema moverse deforma lineal segun el joystick del HMI
		self.velJoystickA = 0 #indica al sistema moverse deforma angula segun el joystick del HMI
		# init node
		rospy.init_node(nodeName)
		rate = rospy.Rate(60)

	def cmd_Callback(self, msg):
		self.motor_cmd = msg.linear.y
		
	def ultra_fault(self, msg):
		self.dist = msg.data

	def btn_manual(self, msg):
		self.manual = msg.data

	def btn_seguidordeLinea(self, msg):
		self.seguidordeLinea = msg.data

	def btn_estacion1(self, msg):
		self.estacion1 = msg.data

	def btn_estacion2(self, msg):
		self.estacion2 = msg.data

	def cmd_velJoystick(self, msg):
		self.velJoystickL = msg.linear
		self.velJoystickA = msg.angular

#		print(dist)		
#		if dist < 40: # These are cm
#			self.motor_cmd = 0
#			print("Oskyselacome")
		

	def setVelocity(self):
		######### SMARTRIS #######################
		node = "motorRight"
		obj = '60FF'
		k = 100
		#########################################
		try:
			#get cmd_vel.linear.y value and use service to move motor

			# Check if the ultrasonic is being blocked
			if self.dist < 40:
				self.motor_cmdc= 0	
				print("ALTO")
				print("Dato enviado: ", self.motor_cmdc)
				vel_service_call = self.set_object(node, obj, str(self.motor_cmdc * 10), False)
#			print("motor in motion", self.motor_cmd)
			else:
				print("Dato enviado: ", self.motor_cmd)
				vel_service_call = self.set_object(node, obj, str(self.motor_cmd * 10), False)
		
		except rospy.ServiceException as e:
			# catch any errors
			print("Service call failed: %s"%e)


#------------------------Main-------------------------------
if __name__ == "__main__":
	name = "app"
	node_app = AppSmartris(name)
	velocidad= 0
	print("Running main ...")
	while not rospy.is_shutdown():
	# while node active
		try:
			node_app.setVelocity()
		except rospy.ROSInterruptException:
			print("Killed node", name)





