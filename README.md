*This site is open source and under a public domain license (alternatively a creative commons license), so the content (or parts of it) can be used in (or modified for) any other project or wiki.*

# Spot-On Encryption Suite

Spot-On is an open-source Encrpytion Suite for secure Chat & E-Mail, File Transfer and also Websearch in a F2F distributed URL-Database.

Means: Spot-On is a Messaging and File-Transfer Application. With RSS you can import, read, search and distribute your feeds f2f to your friends over encrypted connections.  
Enhanced encryption processes have been invented and improved for implementation in Spot-On: such as McEliece-Messaging (Linux), Cryptographic Calling, Zero-Knowledge-Proofs, AutoCrypt via REPLEO and EPKS, Fiasco Forwarding, POPTASTIC-Messaging over E-Mail-Servers, Chipher-Text conversion tools like Rosetta Crypto Pad, Socialist-Millionaire-Security and many more.  

Spot-On utilized the Echo-Protocol for proxyfying and anonymizing the network, it provids end-to-end encryption (and therefore utilizes not a web-of-trust, which is only point-to-point encryption). Spot-On is in the groupchat and for servers compatible with Smoke Crypto Chat Messenger from F-Droid.org


# Download & Install

Install the latest Linux or Mac Version (Tree Icon) or choose the older Win32-Version (Dolphin Icon):

Download Linux: https://github.com/textbrowser/spot-on/releases/download/2023.12.15/Spot-On-2023.12.15_amd64.deb

Download Win 32: https://github.com/textbrowser/spot-on/releases/download/2023.01.15/Spot-On.zip

Download Mac: https://github.com/textbrowser/spot-on/releases/download/2023.12.15/Spot-On-2023.12.15.d.dmg


**Application-Data:**
```
Application-Name:     Spot-On (Encryption Suite)
Developer:            Textbrowser
Start of Development: 2010	
Initial Release:      2013
Actual Version:       Version 2023
Latest Release:       2023
Operating Systems:    Android, FreeBSD, Linux, MacOS, OS/2, OpenBSD, Windows and all systems cappable of Qt.
Coding Language:      C++, Qt 5.15 LTS or Qt 6.5 LTS is required for Linux.
                      All other operating systems require Qt 6.5 LTS.
Categories:           Chat, Instant Messenger, E-Mail, Newsgroups, Anonymous Filesharing, Social Network,
                      Internet Relay Chat, P2P, F2F, Websearch, Encryption, Cryptography, Echo-Application
License:              BSD (Free and Open Source Software)
Website:              https://textbrowser.github.io/spot-on/
```



# Specification-List in Detail

<ul>
<li> <b>Alpha processors:</b> Alpha Chips have been used by HP in Alpha-Servers until 2013 and are still mostly deployed in Supercomputers. Also the Alpha AXP was used by Microsoft to develop the first 64-bit version of Windows Server. The fastest Supercomputer based on Alpha processors was the ASCI-Q at Los Alamos National Laboratory and reached an Rmax of 7.727 TFLOPS. Spot-On is cappable to run on these microchips respective native 64-bit architecture.</li>
<li><b>Connection-Protocols:</b> Spot-On Nodes can be connected via Bluetooth, SCTP, TCP, UDP. This broad variety of connection protocols allow protocoll-changes within end-to-end encryption and makes the hops more secure. E.g. Bluetooth-nodes as Trusted Execution Environments (TEEs) can insert encryption packets into TCP-nodes, which are directly connected to the internet. Bluetooth is a short-range wireless technology standard that is used for exchanging data between fixed and mobile devices over short distances and building personal area networks (PANs). The Stream Control Transmission Protocol (SCTP) is a computer networking communications protocol in the transport layer of the Internet protocol suite. Originally intended for Signaling System 7 (SS7) message transport in telecommunication, the protocol provides the message-oriented feature of the User Datagram Protocol (UDP), while ensuring reliable, in-sequence transport of messages with congestion control like the Transmission Control Protocol (TCP). Unlike UDP and TCP, the protocol supports multihoming and redundant paths to increase resilience and reliability. The SCTP reference implementation was released as part of FreeBSD version 7, and has since been widely ported to other platforms. The User Datagram Protocol (UDP) is one of the core communication protocols of the Internet protocol suite used to send messages (transported as datagrams in packets) to other hosts on an Internet Protocol (IP) network. Within an IP network, UDP does not require prior communication to set up communication channels or data paths. UDP uses a simple connectionless communication model with a minimum of protocol mechanisms. TCP provides reliable, ordered, and error-checked delivery of a stream of octets (bytes) between applications running on hosts communicating via an IP network. Major internet applications such as the World Wide Web, email, remote administration, and file transfer rely on TCP, which is part of the Transport layer of the TCP/IP suite. SSL/TLS often runs on top of TCP. </li>
<li><b>Cross-Plattform:</b> Spot-On runs on all systems cappable of Qt, this means e.g. Android, FreeBSD, Linux, MacOS, OS/2, OpenBSD, Windows, etc.</li>
<li> <b>Data-at-Rest-Encryption:</b> Next to Data-in-Transition-Encryption all saved Data-at-Rest is also stored only encrypted in containers: Authenticated and encrypted SQLite and PostgreSQL e.g. for URL databases ensure, that on the hard disc saved data is accessible only with referring password credentials.</li>
<li><b>Future-related Research and Development:</b> While the work on the client as given is completed for now, there are a lot of feature requests in the Github Repositorium and as well future related ToDos in the task list of the code documentation. Currently the main focus in cooperation with the community is to set up servers for the messaging and data respective URL sharing clients, before further client improvment is conducted in the first place. Ongoing Releases are still updating the mainteinance of the compiling process.</li>  
<li><b>Open Source License: </b> Spot-On uses the open source BSD license, which refers to the Client and also to the integrated Server.</li>


<li>Configurable thread priorities.</li>
<li>Custom URL rules.</li>
<li>Custom socket options.</li>
<li>DSA, ECDSA, EdDSA, ElGamal, McEliece, NTRU, RSA.</li>
<li>DTLS.</li>
<li>Debian packages.</li>
<li>Distributed URL system.</li>
<li>Distributed e-mail.</li>
<li>Dooble, Firefox, Lynx, etc. support for custom search engine.</li>
<li>E-mail (IMAP, POP, Spot-On).</li>
<li>Echo public-key distribution system.</li>
<li>End-to-End, not Hop-to-Hop encryption.</li>
<li>Fortuna.</li>
<li>GPG-lite via Rosetta.</li>
<li>Human Proxies project.</li>
<li>Infinite listeners and neighbors.</li>
<li>Integrated file encryption of directories and files.</li>
<li>Living documentation.</li>
<li>MacOS and Windows install targets: make install!</li>
<li>Messaging.</li>
<li>Multitasking kernel.</li>
<li>Native virtual keyboard.</li>
<li>Natively compiled on ARM, Alpha, PowerPC, Sparc64, X86, X86_64.</li>
<li>Optional SSL/TLS client and server roles: ECC, RSA.</li>
<li>P2P TCP server-less (without accept()) connections.
    SSL/TLS is supported!</li>
<li>Poptastic, or, communications through e-mail. IMAP, POP3, SMTP.</li>
<li>Portable.</li>
<li>PowerPC.</li>
<li>Qt 5.5.1 (PowerPC).</li>
<li>Qt LTS.</li>
<li>Private applications. Stream through Spot-On.</li>
<li>Private group communications.</li>
<li>RSS feeder.</li>
<li>Raspberry Pi.</li>
<li>Record e-mail of offline destinations.</li>
<li>Remote accounts.</li>
<li>Rosetta stationery.</li>
<li>Search engine via PostgreSQL and SQLite.</li>
<li>Simple software firewall.</li>
<li>Socialist Millionaires Protocol.</li>
<li>Sparc.</li>
<li>Themes.</li>
<li>Threefish CBC.</li>
<li>UDP multicast, unicast.</li>
<li>Ultra StarBeam file sharing. TCP through the Echo.</li>
<li>WebSockets.</li>
<li>Windows portable.</li>
</ul>

Please visit https://github.com/textbrowser/spot-on/tree/master/branches/trunk/Documentation for more information.

![Spot-On](https://github.com/textbrowser/spot-on/blob/master/Wiki/spot-on-android.png)



# References
Manual:
[Edwards_Spot-On-Encryption-Suite_-_9783749439829.pdf](https://github.com/user-attachments/files/15521838/Edwards_Spot-On-Encryption-Suite_-_9783749439829.pdf)
