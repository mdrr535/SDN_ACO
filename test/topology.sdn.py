from mininet.net import Mininet
from mininet.node import Controller, RemoteController, OVSKernelSwitch
from mininet.cli import CLI
from mininet.log import setLogLevel
from mininet.link import TCLink

def topology():
	net = Mininet(controller=RemoteController, link=TCLink, switch=OVSKernelSwitch)

	c0 = net.addController('c0', controller=RemoteController, ip='127.0.0.1', port=6653)

	

	s1 = net.addSwitch('s1')
	s2 = net.addSwitch('s2')
	s3 = net.addSwitch('s3')
	s4 = net.addSwitch('s4')
	s5 = net.addSwitch('s5')
	s6 = net.addSwitch('s6')
	s7 = net.addSwitch('s7')
	s8 = net.addSwitch('s8')
	s9 = net.addSwitch('s9')
	s10 = net.addSwitch('s10')
	s11 = net.addSwitch('s11')
	s12 = net.addSwitch('s12')

	net.addLink(s2, s1, 1, 1, bw=1, delay='15ms', loss=0)
	net.addLink(s5, s2, 1, 2, bw=1, delay='7ms', loss=0)
	net.addLink(s4, s5, 1, 2, bw=1, delay='5ms', loss=0)
	net.addLink(s3, s4, 1, 2, bw=1, delay='10ms', loss=0)
	net.addLink(s1, s3, 2, 2, bw=1, delay='17ms', loss=0)
	net.addLink(s3, s2, 3, 3, bw=1, delay='4ms', loss=0)
	net.addLink(s4, s2, 3, 4, bw=1, delay='8ms', loss=0)
	net.addLink(s6, s4, 1, 4, bw=1, delay='15ms', loss=0)
	net.addLink(s5, s6, 3, 2, bw=1, delay='8ms', loss=0)
	net.addLink(s8, s3, 1, 4, bw=1, delay='27ms', loss=0)
	net.addLink(s6, s8, 3, 2, bw=1, delay='7ms', loss=0)
	net.addLink(s9, s6, 1, 4, bw=1, delay='20ms', loss=0)
	net.addLink(s8, s9, 3, 2, bw=1, delay='17ms', loss=0)
	net.addLink(s7, s8, 1, 4, bw=1, delay='5ms', loss=0)
	net.addLink(s3, s7, 5, 2, bw=1, delay='12ms', loss=0)
	net.addLink(s7, s4, 3, 5, bw=1, delay='13ms', loss=0)
	net.addLink(s4, s9, 6, 3, bw=1, delay='7ms', loss=0)
	net.addLink(s12, s7, 1, 4, bw=1, delay='8ms', loss=0)
	net.addLink(s9, s12, 4, 2, bw=1, delay='18ms', loss=0)
	net.addLink(s10, s7, 1, 5, bw=1, delay='17ms', loss=0)
	net.addLink(s11, s10, 1, 2, bw=1, delay='11ms', loss=0)
	net.addLink(s12, s11, 3, 2, bw=1, delay='10ms', loss=0)
	net.addLink(s8, s12, 5, 4, bw=1, delay='12ms', loss=0)
	net.addLink(s10, s8, 3, 6, bw=1, delay='16ms', loss=0)
	net.addLink(s9, s10, 5, 4, bw=1, delay='9ms', loss=0)

	c0.start()
	s1.start([c0])
	s2.start([c0])
	s3.start([c0])
	s4.start([c0])
	s5.start([c0])
	s6.start([c0])
	s7.start([c0])
	s8.start([c0])
	s9.start([c0])
	s10.start([c0])
	s11.start([c0])
	s12.start([c0])
	net.build()

	
	CLI(net)
	net.stop()

if __name__ == '__main__':
	setLogLevel( 'info' )
	topology()

