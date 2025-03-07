*This site is open source and under a public domain license (alternatively a creative commons license), so the content (or parts of it) can be used in (or modified for) any other project or wiki.* Website forked and summarized with more screenshots from: https://github.com/textbrowser/spot-on - URL of this Site: https://sammysupport.github.io/spot-on/ 

# Spot-On Encryption Suite


Spot-On is an open-source Encrpytion Suite for secure Chat & E-Mail, File Transfer and also Websearch in a F2F distributed URL-Database.

Means: Spot-On is a Messaging and File-Transfer Application. With RSS you can import, read, search and distribute your feeds f2f to your friends over encrypted connections.  
Enhanced encryption processes have been invented and improved for implementation in Spot-On: such as McEliece-Messaging (Linux), Cryptographic Calling, Zero-Knowledge-Proofs, AutoCrypt via REPLEO and EPKS, Fiasco Forwarding, POPTASTIC-Messaging over E-Mail-Servers, Chipher-Text conversion tools like Rosetta Crypto Pad, Socialist-Millionaire-Security and many more.  

Spot-On utilized the Echo-Protocol for proxyfying and anonymizing the network, it provids end-to-end encryption (and therefore utilizes not a web-of-trust, which is only point-to-point encryption). Spot-On is in the groupchat and for servers compatible with Smoke Crypto Chat Messenger from F-Droid.org

**Spot-On: 1:1-Chat-Window and "Chat-Tab"**
![Spot-On_Chatwindows.png - Spot-On - 1:1-Chat-Window and "Chat-Tab"](https://github.com/Sammysupport/spot-on/assets/153425149/97b2d6bc-f343-4e65-a487-e1b7e4593293)

# Download & Install

**Download from the Github-project-page:**

Install the latest Linux or Mac Version (Tree Icon) or choose the older Win32-Version (Dolphin Icon):

Download Linux: https://github.com/textbrowser/spot-on/releases/download/2023.12.15/Spot-On-2023.12.15_amd64.deb

Download Win 32: https://github.com/textbrowser/spot-on/releases/download/2023.01.15/Spot-On.zip

Download Mac: https://github.com/textbrowser/spot-on/releases/download/2023.12.15/Spot-On-2023.12.15.d.dmg

**Spot-On: Login-Page & Options: Minimal View - just a few buttons**
![Spot-On_Minimal-View-Options.png - Spot-On: Login-Page & Options: Minimal View - just a few buttons](https://github.com/Sammysupport/spot-on/assets/153425149/1cff8fcd-e86e-4212-adc1-7aa024941bbf)

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

**Reviews of Download-Portals:**

* **Softpedia:** https://www.softpedia.com/get/Internet/Chat/Spot-On.shtml  -  (*"Rating 4.9 of 5 Stars by over 60 ratings"*)

* **Majorgeeks** https://www.majorgeeks.com/files/details/spot_on.html - (*"Spot-On Encryption Suite: for Chat, E-Mail, File Transfer & Websearch is a versatile communication app that allows you to stay connected with your contacts through several different channels. You can send instant messages, emails, and even share files with your contacts. Additionally, it lets you create a chatroom for group conversations."*)

* **Download.com** https://download.cnet.com/spot-on-encryption-suite-for-secure-chat-e-mail-file-transfer-filesharing-p2p-websearch/3000-2150_4-78706448.html - (*"Establish secure, encrypted connections with multifunctional software offering chat, email, and file sharing."*)

* **Apponic:** https://spot-on-encryption-suite.apponic.com/ - (*"Securely connects with your contacts on instant messaging, emails."*)

* **F-Droid.org:** https://f-droid.org/de/packages/org.purple.smoke/ - (*Server and Groupchat compatibility: Mobile Messenger compatible with Spot-On*)


# Specification-List in Detail

<ul>
<li> <b>Alpha processors:</b> Alpha Chips have been used by HP in Alpha-Servers until 2013 and are still mostly deployed in Supercomputers. Also the Alpha AXP was used by Microsoft to develop the first 64-bit version of Windows Server. The fastest Supercomputer based on Alpha processors was the ASCI-Q at Los Alamos National Laboratory and reached an Rmax of 7.727 TFLOPS. Spot-On is cappable to run on these microchips respective native 64-bit architecture.</li>
<li><b>Connection-Protocols:</b> Spot-On Nodes can be connected via Bluetooth, SCTP, TCP, UDP. This broad variety of connection protocols allow protocoll-changes within end-to-end encryption and makes the hops more secure. E.g. Bluetooth-nodes as Trusted Execution Environments (TEEs) can insert encryption packets into TCP-nodes, which are directly connected to the internet. Bluetooth is a short-range wireless technology standard that is used for exchanging data between fixed and mobile devices over short distances and building personal area networks (PANs). The Stream Control Transmission Protocol (SCTP) is a computer networking communications protocol in the transport layer of the Internet protocol suite. Originally intended for Signaling System 7 (SS7) message transport in telecommunication, the protocol provides the message-oriented feature of the User Datagram Protocol (UDP), while ensuring reliable, in-sequence transport of messages with congestion control like the Transmission Control Protocol (TCP). Unlike UDP and TCP, the protocol supports multihoming and redundant paths to increase resilience and reliability. The SCTP reference implementation was released as part of FreeBSD version 7, and has since been widely ported to other platforms. The User Datagram Protocol (UDP) is one of the core communication protocols of the Internet protocol suite used to send messages (transported as datagrams in packets) to other hosts on an Internet Protocol (IP) network. Within an IP network, UDP does not require prior communication to set up communication channels or data paths. UDP uses a simple connectionless communication model with a minimum of protocol mechanisms. TCP provides reliable, ordered, and error-checked delivery of a stream of octets (bytes) between applications running on hosts communicating via an IP network. Major internet applications such as the World Wide Web, email, remote administration, and file transfer rely on TCP, which is part of the Transport layer of the TCP/IP suite. SSL/TLS often runs on top of TCP. </li>
<li><b>Cross-Plattform:</b> Spot-On runs on all systems cappable of Qt, this means e.g. Android, FreeBSD, Linux, MacOS, OS/2, OpenBSD, Windows, etc.</li>
<li> <b>Data-at-Rest-Encryption:</b> Next to Data-in-Transition-Encryption all saved Data-at-Rest is also stored only encrypted in containers: Authenticated and encrypted SQLite and PostgreSQL e.g. for URL databases ensure, that on the hard disc saved data is accessible only with referring password credentials.</li>
<li><b>Debian packages:</b> Debian is a community-developed free operating system. Debian GNU/Linux is based on the basic system tools of the GNU project and the Linux kernel. It is one of the oldest, most influential and most widely used GNU/Linux distributions. Many other Linux distributions are based on Debian, of which Ubuntu is the best known. Dpkg is the basis of the package management of the Debian operating system and the basic program for installing Debian binary packages (file extension “.deb”). Spot-On is available in .deb installation packages. The cryptographic libraries in particular recommend using a Linux operating system, as these can always be implemented in the respective current reference.</li>
<li><b>Distributed e-mail (P2P / F2F):</b> Based on the cryptographical functions Spot-On provides not only encryption of the regular e-mail via IMAP or POP3, it also has a distributed e-mail included: so called "e-mail institutions" and "care-of (C/O)" are two methods to store encrypted e-mails of Spot-On within friends respective dedicated nodes of the network.</li>  
<li> <b>DTLS: </b> Datagram Transport Layer Security (DTLS) is an encryption protocol based on Transport Layer Security (TLS) which, unlike TLS, can also be transmitted via connectionless, unreliable transport protocols such as the User Datagram Protocol (UDP). An initial draft in February 2004 was implemented in OpenSSL until DTLS 1.3 was published in RFC 9147 in April 2022. The functionality of DTLS largely corresponds to that of TLS. Spot-On therefore implemented an up-to-date encryption protocol that can also be transmitted via connectionless, unreliable transport protocols such as the User Datagram Protocol (UDP): DTLS. The grants of secure transmission are: (1) Re-establishing the reliability of the handshake at the beginning of the communication, since in this part the arrival of all packets must be guaranteed in order to enable authentication and key exchange. This is done by resending the packets after a certain time. (2) Explicit numbering of the individual packets during transmission. With TLS, this is only done implicitly, which means that correct HMAC can no longer be calculated in the event of packet loss, which represents an integrity violation and in turn leads to a connection being terminated. (3) Optional replay detection for individual packets. The need that has arisen, for example with Voice over IP (VoIP) and the SIP signaling protocol widely used there, to transfer the security provided by TLS for SIP via TCP to transport via UDP - is covered by the DTLS implementation at Spot-On and lays the foundations for future implementations, e.g. with regard to VoIP based on the Echo-Protocol. This is because TLS itself is not suitable for this, as none of the packets following a packet loss can be authenticated.</li> 
<li><b>Echo public-key distribution system: </b> Echo Public Key Sharing (EPKS) is a distributed public-key-sharing system. Share public-keys in a secure channel with other users or teams and communities. </li>
<li><b>E-Mail:</b> Spot-On is an E-mail-Client (for IMAP, POP, Spot-On network e-mail).</li>
<li><b>Encryption Algorithms:</b> DSA, ECDSA, EdDSA, ElGamal, McEliece, NTRU, RSA. Spot-On is known as the first *Desktop* Messenger next to Smoke *Mobile* Crypto Chat Messenger to have utilized McEliece-Messaging in the application. Quantum computers can break the RSA, El Gamal, and elliptic curve public-key cryptosystems, as they can efficiently factor integers and extract discrete logarithms. The McEliece cryptosystem is an asymmetric encryption algorithm developed in 1978 by Robert McEliece. It was the first such scheme to use randomization in the encryption process. The algorithm is today a candidate for "post-quantum cryptography", as it is immune to attacks using Shor's algorithm ("finding the prime factors of an integer"), e.g. utilized by Quantum Computers, and – more generally – measuring coset states using Fourier sampling. Fourier sampling is a powerful technique in quantum computing that allows us to efficiently extract information from quantum circuits. It is based on the principles of the Fourier transform, a mathematical operation that decomposes a function into its frequency components. Spot-On Encryption Suite provides with McEliece Quantum Computer secure Communications and File-Transfer. </li>
<li><b>End-to-End, not Hop-to-Hop encryption: </b> While e-mail and chat often provide end-to-end encryption (as also Spot-on) file-transfer and sharing applications mostly do not support end-to-end encryption. F2F FileSharing has a good standard e.g. with a web-of-trust-architecture. But that is only hop-to-hop encryption. Within Spot-On the filesharing like torrents is real end-to-end encrypted. Spot-On supports the Magnet-URI-standard enhanced with cryptographic values for the encryption.</li>
<li><b>F2F / Friend-to-Friend Websearch based on a Distributed URL system:</b> Spot-On provides a new system of Websearch. There is alreary peer-to-peer (P2P) Websearch within just a few tools. P2P has been turn within Spot-On into F2F Wesearch, which is much more secure, while maintaining the distributed architecture. Next to this new approach it is one of the few search engines, which allow also to download the search index database of others. Do you know a websearch which is distributed? Do you know any websearch, which allows to download the search index database? Spot-On has not only updated P2P to F2F, but  offers next to a distributed approach also the download options of the full database index of this search engines. As the search results a created locally from the own database, there are no so called "queryhits" created within other nodes. The search index can be maintained within a SQLite or PostGres database - up to the expierience of the user to choose.   </li>
<li><b>Filter-Options for Websearch and URL-Database</b>: Custom URL rules can be applied as distillers - they filter domains or keywords and also p2p distributions by users.</li>
<li><b>Fortuna: </b> Fortuna is a function to create random numbers like the NTL library or a PRNG provides. Random numbers are esential in cryptographic processes, especially for the McEliece algorithm.</li>
<li><b>Future-related Research and Development:</b> While the work on the client as given is completed for now, there are a lot of feature requests in the Github repositorium and as well future related ToDos in the task list of the code documentation. Currently the main focus in cooperation with the community is to set up servers for the messaging and data respective URL sharing clients, before further client improvement is conducted in the first place. Ongoing releases are updating the maintenance of the compiling process of Spot-On.</li>  
<li><b>GPG-lite via Rosetta:</b> Roseatta is the conversion pad to transform plaintext into ciphertext and vice versa. There are not many applications providing such a copy/paste conversion pad. Mostly symmetric keys are used. With the GPG introduction in Rosetta it is (one of) the first conversion pad(s) for ciphertext, which uses the symmetrical encryption method based on the standard of GPG. As Spot-On can be connected via bluetooth from a machine not connected to the internet, the Rosetta Encryption Pad with asymmetric GPG respective symmetric encryption is an ideal constitution of a Trusted Execution Environment (TEE) for ciphertext conversion.</li>  
<li><b>Human Proxies:</b> Human Proxies describe a function to send a message over the Echo-Protocol not from the own node, but from the node of a friend (a human proxy). Here a Human Proxies problem or phenomenon is created based on the Echo-Protocol and its graph routes and specialities: how is it judged who the sender of the the same copy is? A mathematical (also social and philosophical) problem of graph routes beyond routing is created. </li>
<li> <b>Individual configuration needs:</b> E.g. thread priorities are individually configurationable. Spot-On can adjust many options for individual needs of use cases of users and research models of cryptographers.</li>
<li><b>Infinite listeners and neighbors:</b> Not only the client is open source, also the server software for Spot-On is open source and the function to create a server is integratred in the application of Spot-On client, see Listeners Tab. Next to the Connection Tab for neighbour nodes, both, Listener (Server) Tab as well as Neighbours Tab allow infinite connections respective Listeners on ports and Neighbours connected for scaling. </li>
<li><b>Integrated file encryption of directories and files:</b> Spot-On contains a File-Cryptor, which also works for directories. Spot-On as application manages your keys and cryptographical processes. Means: next to encypted chat and data in tranit not only the data at rest of Spot-On is stored in encrypted containers, also the data of users can be encrypted as wished and defined for files and directories. A powerful and open source tool to strongly encrpyt individual files or directories.</li>
<li><b>Living documentation:</b> Next to the technical documentation there is also a manual as handbook, which has been published with ISBN and is open source downloadable. The wiki and further pages are living documents also extendable by users and contributing and forking projects. See descritions and tutorials in the web or write and provide your own tutorial.</li>
<li><b>Messaging / McEliece-Messaging:</b> Spot-On is a chat messenger. It utilizes different open source servers, which are integrated into the application, also headless available for Linux and Android. Also regular E-Mail-Accounts and their servers can be addressed via the POPTASTIC protocol for messaging friends. The mobile Delta-Chat App derived from this function of Messaging over E-Mail-Servers via the POPTASTIC protocol. With McEliece-Messaging the quantum-secure Algorithm McEliece is meant, which is also applicable - open source (in the current Linux release and an older Win-32-Release).</li>
<li><b>Multitasking kernel:</b> Spot-On utilizes a kernel, which has to be activated within the settings tab. The kernel is multi-tasking and a fast solution for all the encryption and decryption processes. If you install Spot-On with its Listener function as a server on your webserver, the multi-tasking kernel saved additional CPU-Core, because it is fast enough to serve all participants.</li>
<li><b>Native virtual keyboard:</b> Consider your keyboard probably infected by a keyboard-checker. Spot-On is ahead of these risks and has integrated an own software keybord, which is can be opened, if you double-click in the password field of the login page. Mouse clicks cannot reveal your password. And you think, Spot-On is only for spy-agents of agencies? No. it is about a process to provide a safe insertation of your personal credentials. </li>
<li><b>Natively:</b> Spot-on has been natively compiled on ARM, Alpha, PowerPC, Sparc64, X86, X86_64. Different architectures are addressed by the provided programming and Qt-compiling for these architectures.</li>
<li><b>Open Source License: </b> Spot-On uses the open source BSD license, which refers to the Client and also to the integrated Server.</li>
<li><b>P2P Serverless:</b> Spot-On has an architecture, which does not require a server. It is P2P serverless and this TCP server-less way establishes connections without "accept()". Also SSL/TLS is supported within these P2P connections. A server, e.g. in the web, helps of course NAT-ted clients to connect better. Forwarded ports (e.g. over "IPV6 exposed hosts" with a defined port) help to connect serverless to friends and peers.</li>
<li><b>POPTASTIC:</b> POPTASTIC or, communications through e-mail, provides chat over e-mail-servers and accounts. IMAP, POP3, SMTP. From this POPTASTIC protocol the mobile chat app Delta-Chat derived.</li>
<li><b>Portable:</b> Spot-On is portable. You can move the whole app and its data on a mobile space. All saved data is always in encrypted containers.
The files are saved in the sub-dir:  - /.spot-on (if you want to renew your account, just delete the file-containers in this directory). This means it is a portable app, you need not to install it (e.g. for Windows it is just a zip to unzip), also you can just copy the path into another place. Portable means also, that is is cross-compiling to different operating systems. And sure, copy the data and/or the application e.g. on an USB stick - and have your encryption details always secure with you.</li>
<li><b>PowerPC:</b> PowerPC is supported with Qt 5.5.1.</li>
<li><b>Qt-Famework: </b> The Qt-Framework is used with its Long Term Solution: Qt LTS. This also ensures easy Qt-Compiling over e.g. a terminal.</li>
<li><b>Qt-Compiling: </b> MacOS and Windows install targets are easily addressed with Qt over the command: "make install"! - or the Qt-Creator is graphically addressed to compile the source.</li>
<li><b>Patch-Points (encrypt private applications):</b>Private applications (Patch Points) allow to stream through Spot-On. An application with no or insecure encryption can be bound over localhost proxy with Spot-On and establish a connection between two Spot-On-nodes. Spot-On privides like a VPN a strong encryption and secures the transmission of other applications, non-cappable to encrypt. Stream TCP over two Spot-On secured connection-points. This is the concept of Patch-Points for private applications in Spot-On. </li>
<li><b>Private group communications:</b> Private group communications is simply group-chat. It regularly is established over symmetric encryption, but can manually also be created for asymmetric chat. The symmetric encryption of Spot-On (c++) allows also to bridge to mobile chat (Android, Java) and bridges c++ and java encrypted chat with 1:1-group-chat-rooms. </li>
<li><b>RSS feeder:</b>The RSS-feed reader collects not only your bunch of RSS-Feeds you want to read, but also displays the feeds in a timeline, so you will not miss out any news. Furthermore a search engine for keywords in all RSS-Items is implemented. If you want to remember a news from your RSS-items, just search for it in Spot-On. Actually it is a RSS-News search database. This URL- and News-Database can be shared with friends. Get RSS-News from your friends over encrypret connections: Reading BBC-News behind a censoring firewall becomes possible with this shared and distributed RSS-Database over Spot-On. </li>
<li><b>Raspberry Pi:</b>The Pi-4 needs 3-4 Watt energy and the PI-5 needs 5 Watt. You can set up the Pi as as Spot-On-server at home (with forwarded port) and all family members can chat over Spot-On, secure and encrypted. An active chat-server with less energy consumption on the Raspberry-Pi than your TV in standby modus can be created. E.g., a Rasberry-Pi-Ballon in the air with wifi cares for all chatting people on a campsite or in a workshop, even without beeing connected to the internet. Which Chat-Eco-System is comparable to this Echo-Chat-System? </li>
<li><b>Record e-mail of offline destinations:</b> E-mail-Institutions is the name for the function, to provide in a P2P system (or with an intermediate server) the recording of e-mails of offline destinations, nodes and friends. Everyone in the client and eco-system of Spot-On can create a post-box for friends based on the cryptogaphic values given. This introduces new decentral postboxes in an encrypted environment: E-mail to a key.</li>
<li><b>Remote accounts:</b>: Remote Accounts are accounts in a server respective at a listener to provide access to specific networks and IPs.</li>
<li><b>Rosetta Crypto Pad: </b> Rosetta provides stationery in a Text-Pad. Write your text and convert it to ciphertext or vice versa. Either with symmetric encryption or over GPG keys, asymmmetric. A conversion pad named in allusion and accordance with the Stone of Rosetta in the British Museum. </li>
<li><b>Search engine via PostgreSQL and SQLite: </b>: Spot-On saves URLs, Websites and RRS-Feed-News either in SQLite or PostgeSQL databases - means: Spot-On is a decentral P2P/F2F Web-Search-Engine over your imported News-Data.</li>
<li><b>Simple software firewall:</b> With the simple software firewall you keep attackers out. Spot-On needs only one open port and the connection is secured via diffferent software firewalling functions. E.g. the cryptographic values (SSL/TLS and encryption keys) need to be assured, to be able to connect. </li>
<li><b>Socket options:</b> In addition to binding a socket to a local address or connecting it to a destination address, application programs need a method to control the socket. Application programs may also want to control the allocation of buffer space, determine if the socket allows transmission of broadcast, or control processing of out-of-band data, which is a logically independent transmission channel associated with each pair of connected stream sockets. Spot-On provides several custom socket options in this regard. </li>
<li><b>Socialist Millionaires Protocol (SMP):</b> The Socialist Millionaires Protocol (SMP) verifies a password on both sides of e.g. a chat, to ensure authenticity of the friends - without transmitting the password over the internet. It`s near the context of zero-knowledge-proofs, some may have heard of. </li>
<li><b>Sparc:</b> Yes. Sparc. Microprocessors. Scalable Processor ARChitecture - Sun, Oracle, Fujitsu. Open source architecture and also used by supercomputers too.</li>
<li><b>SSL/TLS:</b> Spot-On provides optional SSL/TLS client and server roles: with ECC, RSA. Of coursse, as McEliece has not yet been implemented in a SSL/TLS process. SSL/TLS is within Spot-On used to provide an additional transport encryption, as already the data (e.g. messaging) packet is encrypted, the SSL/TLS process adds another layer of encryption. Spot-On is therefore one of the applications providung multi-encryption: Ciphertext is secured by another layer of encryption, here SSL/TLS - which therefore can be optionally, as it secures already encrypted ciphertext. </li>
<li><b>Themes:</b> Choose Nuvola Iconset or other and explore also the Themas for Spot-On and the minimal-view concept of Spot-On to change the UX experience.</li>
<li><b>Threefish CBC:</b> Threefish is the successor of Twofish and affects the symmetric block-cipher-encryption. Choose this for state-of-the-art encryption. </li>
<li><b>UDP multicast, unicast:</b> UDP either in multicast or unicast modus is an alternative to TCP.</li>
<li><b>Ultra-StarBeam file sharing: </b> USB (Ultra-Star-Beam) introdoces into TCP-E (TCP through the Echo). If you transfer a file in the filesharing tab, your file will be sent encrypted over the Echo-protocol. To male it TCP-like, there is a handshake sent back for each packet-transfer. That makes file transport over the Echo lossless and secure. Futhermore the Ultra-Star-Beam-(USB)-Protocol enables swarming the download from several sources. </li>
<li><b>WebSockets: </b> WebSocket is a computer communications protocol, providing a simultaneous two-way communication channel over a single Transmission Control Protocol (TCP) connection. The WebSocket protocol was standardized by the IETF as RFC 6455 in 2011. The current specification allowing web applications to use this protocol is known as WebSockets. It is designed to work over HTTP ports 443 and 80 as well as to support HTTP proxies and intermediaries.</li>
<li><b>Web-Interface for the F2F Websearch:</b> Webbrowser like Dooble, Firefox, Lynx, etc. support for custom Web search engine by its Webinterface.</li>
<li><b>Windows portable:</b> Yes. Portable and also portable for Windows. See portable. E.g. on a USB-Stick. </li>
</ul>

Please visit https://github.com/textbrowser/spot-on/tree/master/branches/trunk/Documentation for more information.


# Screenshots

**Spot-On: 1:1-Chat-Window and "Chat-Tab"**
![Spot-On_Chatwindows](https://github.com/Sammysupport/spot-on/assets/153425149/97b2d6bc-f343-4e65-a487-e1b7e4593293)

**Spot-On: Group-Chat-Tab called "Buzz"** 
![Spot-On_Groupchat](https://github.com/Sammysupport/spot-on/assets/153425149/e6cf48bf-ff61-4516-9836-f0611b33ff2d)

**Spot-On: Spot-On "Settings-Tab" to activate the kernel (must be done first)**
![Spot-On_Settings_Kernel_Activation](https://github.com/Sammysupport/spot-on/assets/153425149/8882bec2-1020-4483-b283-c7b55b29b84d)

**Spot-On: "Neighbour-Tab" to add a connection to a server or node**
![Spot-On_Neighbour](https://github.com/Sammysupport/spot-on/assets/153425149/339bb07d-deb6-426f-ab41-65acced8dc69)

**Spot-On: Login-Page & Options: Minimal View - just a few buttons (without search)**
![Spot-On_Minimal-View-Options](https://github.com/Sammysupport/spot-on/assets/153425149/1cff8fcd-e86e-4212-adc1-7aa024941bbf)

**Spot-On: Create a Server / Listener just with a few clicks**
![Spot-On_Listener_Server](https://github.com/Sammysupport/spot-on/assets/153425149/05a5e259-67bc-4c18-8121-b125c9d587c2)

**Spot-On: FileSharing with Magnet-Links - "StarBeam-Tab" or to be StarBeamed in the Chatwindow**
![Spot-On_FileSharing_Torrent_Magnet](https://github.com/Sammysupport/spot-on/assets/153425149/fb8e404c-d597-49b7-8062-34920cab026f)

**Spot-On: Websearch - here: Webinterface in a webbrowser**
<img alt="Spot-On_Websearch_Webinterface" src="https://github.com/Sammysupport/spot-on/assets/153425149/ca75a34c-75a4-496f-8d94-77bf1ef2de13">

**Spot-On: Websearch 2 - here: client-interface in a tab**
<img alt="Spot-On_Websearch_Clientinterface" src="https://github.com/Sammysupport/spot-on/assets/153425149/6ad22197-084a-478a-a155-e19737d6f8fa">


# Bibliographic References, Literature, Papers & Articles:  

* Adams, D. & Maier, A.-K. (2016): Big Seven Study 2016 - 7 open source Crypto-Messengers to be compared, ISBN 978-3750408975.
* Bertram, L. A. / van Dooble, G. (2019): Transformation of Cryptography, 2019, deutsch: Die Transformation der Kryptographie, ISBN: 978-3749450749.
* Bro, T. (2024): Echo-Protokoll, in: Bro, T. (2024): Lexikon der Informatik, Datenverarbeitung und Kryptographie - Mit über 1000 Übungs-Aufgaben für Lernende, ISBN 978-3758368158.
* Edwards, S. (2023): Spot-On - Eine moderne Verschlüsselungs-Suite im Echo, in: Sobiraj, L. (Hg.): Unter dem Radar - Ausgewählte Artikel und Interviews zu Datenschutz, Informationstechnologie, Netzpolitik und Hacking, Norderstedt, pp 133-145.
* Edwards, S.: Spot-On (2022) : A modern encryption suite in the Echo, Article Magazin TK Info Portal.
* **Gasakis, M. / Schmidt, M. (2018): Beyond Cryptographic Routing: The Echo Protocol in the new Era of Exponential Encryption (EEE), ISBN 978-3-7481-5198-2.**
* Lindner, M. (2014): POPTASTIC: Verschlüsselter Chat über POP3, Pro-Linux Magazin, 9. Dezember.
* Moonlander, C. (2020): Smoke - An Android Echo Chat Software Application: Open Source Technical Website Reference Documentation 2020-11-15, ISBN 9783752691993 & 9783752692006.
* Nomenclatura (2019): Encyclopedia of modern Cryptography and Internet Security: From AutoCrypt and Exponential Encryption to Zero-Knowledge-Proof Keys, ISBN: 978-3748191513.
* Rahmschmid, C. / Adams, D. (2023): McEliece Messaging: Smoke Crypto Chat - The first mobile McEliece-Messenger published as a stable prototype worldwide, Article Magazin TK Info Portal, and published in: Sobiraj, L. (Hg.): Unter dem Radar - Ausgewählte Artikel und Interviews zu Datenschutz, Informationstechnologie, Netzpolitik und Hacking, pp. 73-83.
* Smoke (2017): Documentation of the Android Messenger Application Smoke with Encryp-tion, URL: https://github.com/textbrowser/smoke/raw/master/Documentation/Smoke.pdf, 2017.
* SmokeStack (2017): Server Software for Encrypted Messaging, URL: https://github.com/textbrowser/smokestack.
* **Spot-On Encryption Suite Handbook (2019): Democratization of Multiple & Exponential Encryption: - Handbook and User Manual as practical software guide, ISBN: 978-3749435067. https://github.com/Sammysupport/spot-on/blob/ff1208f76217fa41252775f2c24fec2b73ee3865/Edwards_Spot-On-Encryption-Suite_-_9783749439829.pdf** 
* Tenzer, T. (2022): Super Secreto - The Third Epoch of Cryptography: Multiple, exponential, quantum-secure and above all, simple and practical Encryption for Everyone, ISBN 978-3755761174.
* Tenzer, T. (2022): Spot-On Encryption Suite, in: Verschlüsselung für alle: Abhörsicher in die Dritte Epoche der Kryptographie, ISBN: 978-3755758112.
* **Textbrowser (2011 - current): Documentation of the Spot-On-Application, URL: https://github.com/textbrowser/spot-on/tree/master/ branch-es/trunk/Documentation, Github; & was: https://sourceforge.net/p/spot-on/code/HEAD/tree/ & RELEASE-NOTES.archived, 08.08.2011.**
* Wake, M.A. et. al. (2020): Echo on a Chip (EoC) – A New Perception for the Next Generation of Micro-Controllers handling Encryption for Mobile Messaging. ISBN 9783751916448.


# Research-Article on Spot-On: Spot-On Encryption Suite: Features, Security, and Comparison

Main Features and Supported Encryption Methods: Spot-On is an open-source encryption suite designed for secure communication across multiple channels, including 1:1 and group chats, an email client, file transfers (via Magnet links similar to BitTorrent), and a decentralized web search based on a distributed Friend-to-Friend (F2F) database. All communication channels are end-to-end encrypted.

Spot-On supports a broad range of cryptographic methods, including classic public-key algorithms like RSA, DSA, and ElGamal, as well as modern elliptic curve methods such as ECDSA/EdDSA. Additionally, it incorporates as first desktop-chat-messenger post-quantum algorithms such as McEliece and NTRU. For symmetric encryption, Spot-On employs Threefish (a block cipher in CBC mode). It also supports authenticated encryption (ensuring data integrity) and optional SSL/TLS for secure connections.

Special features include the Socialist’s Millionaires Protocol (a zero-knowledge proof for key agreement), general Zero-Knowledge-Proofs, and a Rosetta Crypto Pad for offline encryption (also with GPG). This extensive range of encryption methods makes Spot-On one of the most functionally rich encryption suites available for communication security.

Supported Platforms: Spot-On is cross-platform and developed in C++ with Qt. It runs on operating systems that support Qt (version 5.15/6.5+), including Windows, macOS, Linux, and even niche systems like FreeBSD, OpenBSD, OS/2, and Qt-support for Android.

Precompiled binaries are available for Windows, macOS and Debian, while further Linux users can compile the source code. Spot-On supports various networking protocols (TCP, UDP, SCTP, Bluetooth), allowing it to function across different network environments, including local Bluetooth-based networks.

Use Cases and Applications: Spot-On is designed for secure peer-to-peer communication using an F2F topology. It is ideal for groups or communities that require confidential communication and file sharing without relying on centralized servers. This application with its features include:

Alternative to mainstream messaging & file-sharing platforms for groups of friends, work teams, or journalists needing privacy.
End-to-end encrypted file transfers using the StarBeam feature, which operates similarly to torrents but within a fully encrypted group/network.
Decentralized web search where participants contribute to and use a shared encrypted URL database via RSS feeds.
POPTASTIC - Chat over E-Mail-Servers: The Poptastic function enables users to exchange encrypted messages via standard email servers (POP3/IMAP/SMTP), even in environments where P2P connections are blocked.
High-privacy networks: Spot-On can be configured to operate entirely over Tor for additional anonymity.
A practical example would be a private chat group using Spot-On to securely exchange information and files without exposing their metadata, unlike traditional platforms like IRC or FTP.

Security Features and Evaluation: Advanced Multi-Hop End-to-End Encryption - Unlike many traditional F2F networks that encrypt only between immediate neighbors (like e.g. RetroShare), Spot-On ensures end-to-end encryption even when data is relayed through multiple hops. This means no intermediary can decrypt or inspect messages.

Anonymizing Echo Protocol: Spot-On employs a unique Echo Protocol, which has no sender and receiver IP addresses information from transmitted data packets. Messages are forwarded through peers, with each relay re-encrypting the data, ensuring that even nodes acting as intermediaries cannot track the message source or destination.

Strong and Versatile Cryptography: Spot-On uses both classical and post-quantum algorithms, ensuring resistance to potential quantum computing attacks. The software also provides a customizable cipher/hash selection during setup. Additionally, it features a proprietary Echo Public Key Sharing (EPKS) system for secure key exchange within a community.

Open Source and Transparent Development: Spot-On is released under a BSD license and has been in development since 2010. The source code is publicly available, enabling external audits and community-driven improvements. Next to the option of formal security audits, the project's commitment to open-source development suggests no hidden backdoors, as everything is open and proveable.

Reviews have praised Spot-On’s high cryptographic density and security, its learning model and content means it is best for general consumers wanting to deepen the tech-savvy knowledge.

Spot-On offers the most advanced encryption with multi-hop end-to-end protection and post-quantum cryptography, but is technically complex and requires manual setup. It is a user-friendly alternative for encrypted social networking (forums, chats, and file-sharing), and its encryption is not only hop-to-hop but rather provides full E2E multi-hop.

Availability and Maintenance: Spot-On is actively maintained and regularly updated. The software is available as an open-source project on GitHub, with binary releases for Windows, macOS, and Linux.

The project is developed by an individual known as “Textbrowser”, and the BSD licensing allows its code to be freely modified or incorporated into other projects. The Spot-On community is suppoting through available forums.

Spot-On provides an actively maintained project, with recent updates released at the end of the last year. Users looking for a high-security, decentralized communication suite with state-of-the-art encryption will find Spot-On a robust solution, no one should have missed to study and share the exploring with friends.


# Semi-compatible Mobile Messenger with Spot-On: Smoke Crypto Chat Messenger: An additional Analysis

Smoke Crypto Chat is an open-source messenger focused on maximum security. It is regarded as the world's first mobile messenger to use the post-quantum secure McEliece algorithm for encryption. The app enables end-to-end encrypted chats without requiring a phone number, supports self-hosted decentralized servers, and implemented cryptographic concepts for enhanced forward secrecy. Below, we examine its features, security, supported platforms, user experiences, origin, and parallels with other secure messengers based on the Echo-Protocol like the Desktop-Messenger Spot-On.

Features and Unique Aspects
End-to-End Encrypted Chats: Smoke offers individual chats as well as a group chat in IRC style ("Fire" channels) with symmetric group key encryption. All conversations are end-to-end encrypted by default. Group-Chats (also 1:1-Fire-Chats) are compatible with Chats on Spot-On (for Desktop).

Messaging and Data Exchange: In addition to text messages, emojis and images can be sent. Received images are stored in an encrypted container on the smartphone and must first be decrypted before being exported for external use. It is also possible to send any type of file — even to recipients who do not have the Smoke client: Files can be encrypted and transferred via standard tools (e.g., to an SSH client). This is handled via the integrated "Steam" protocol, which ensures reliable file transfers (TCP over the Echo network).

No Phone Number Required: Users identify themselves via a random 32-character chat ID instead of a phone number. Automatic contact list uploads do not occur, providing a key privacy advantage (GDPR compliance) over messengers that scan address books. To simplify usage, each user can in addition define an alias (e.g., a term like "Berlin") that the chat partner must also enter to establish a connection. Using this shared alias, the clients automatically exchange public keys and start the secure chat. This method replaces central key servers with an AutoCrypt-like mechanism (known from Spot-On as EPKS), making key exchange simpler.

Self-Hosted Servers & Decentralization: Smoke is based on the decentralized Echo protocol instead of centralized servers. Messages can run through the built-in SmokeStack server — a simple server app for Android. This allows users to set up easily a personal chat server on an old Android device at home, in a classroom, or in a small group. Alternatively, users can run their own server instances or use public Echo servers. This federated model allows schools, organizations, or municipalities to deploy their own private messenger server rather than relying on foreign cloud services.

Direct and Offline Communication: Smoke can theoretically function without an internet connection. Devices on the same local network (or via Bluetooth/TCP direct connection) can communicate directly since no registration or external infrastructure is required. For offline messages, Smoke uses Ozone mailboxes: If a message is sent while the recipient is offline, it is temporarily stored until the recipient accesses a shared Ozone mailbox (on one or more known SmokeStack servers) to retrieve it. This ensures that messages are not lost even when both devices are not online at the same time.

Multi-Media and Additional Features: The app provides additional functions, such as an app lock (password protection for the app), and modern key derivation algorithms (Argon2id, PBKDF2). Smoke also includes special modes like “Silent Mode” (no visible status metadata to outsiders) and the ability to relay messages through network neighbors. It even supports real-time file sharing to multiple recipients (“Steamrolling”) and integration with external tools (e.g., Netcat for file transfer).

Security & Encryption Technologies: Smoke was specifically developed to ensure maximum confidentiality, even in the age of quantum computers. The security architecture combines classical methods with advanced cryptographical implementations:

Post-Quantum Encryption (McEliece): The core encryption algorithm is McEliece, which has been known for over 40 years and is considered resistant to all known quantum computer attacks. Smoke is the first mobile messenger worldwide to use McEliece encryption. Each user account has a key pair (private and public key)—either based on McEliece (offering four different parameter/moduli sets) or alternatively RSA. Notably, Smoke enables chats between a McEliece user and an RSA user, ensuring backward compatibility while encouraging quantum-safe communication.

Symmetric Encryption and Forward Secrecy: For actual message transmission, Smoke uses authenticated encryption with changing session keys. Smoke implements a proprietary concept called "Fiasco Forwarding" (FF) to ensure perfect forward secrecy. Instead of deriving the key for each message from the previous one (as in Signal’s Double-Ratchet protocol), Smoke transmits a bundle of temporary keys ("Fiasco-Keys") per message, which are stored in the recipient’s cache and used successively. This less deterministic, more volatile approach increases security: if a single session key is compromised, it does not allow decryption of all subsequent messages.

Password-Protected Chats (CSEK/JPAKE): In addition to public-key encryption, Smoke offers an option for user-defined passwords, called “Customer Supplied Encryption Key” (CSEK). Both chat partners can agree on a shared password beforehand, which they enter into the app. This enables a secure symmetric session key exchange, likely implemented via J-PAKE (Password-Authenticated Key Exchange). This provides an additional secured communication channel, even if the public-key infrastructure were compromised.

Further Cryptography & Techniques: Smoke integrates numerous additional security technologies. It minimizes metadata exposure, avoiding identifiable headers and using SipHash-128 for ID generation and automatic public-key exchange. Additionally, messages are double-encrypted: first end-to-end encrypted, and second, the transport to the SmokeStack server is always TLS-encrypted.

Comparison with Other Secure Messengers
Smoke Crypto Chat competes with established secure messengers. Here’s how it compares:

💬 End-to-End Encryption: Messengers like Signal, Threema, WhatsApp, and Element/Matrix provide end-to-end encrypted chats like Smoke. However, they rely on Elliptic Curve Cryptography (Curve25519, Double Ratchet), which may not be quantum-safe. Smoke uses McEliece, ensuring future-proof encryption.

Forward Secrecy & Key Management: Standard messengers use a single new key per message (e.g., Signal's Double-Ratchet). Smoke goes further, sending multiple keys per message (Fiasco Forwarding), increasing security but adding complexity.

Identification & Privacy: WhatsApp and Signal require a phone number, which reduces privacy. Threema and Smoke use random IDs, eliminating phone number dependency.

Centralization vs. Decentralization: Signal, WhatsApp, and Telegram use centralized servers. Matrix/XMPP allow federation but require complex server setup. Smoke simplifies self-hosting with an Android-based server (SmokeStack), making it easier to decentralize.

Advantages:
✔️ Post-Quantum Encryption
✔️ No phone number required
✔️ Self-hosted servers
✔️ Works offline/local network

Future & Community development:
❌ Technical UI, which could have a make-over in a community fork and: voice files can be transferred, live video calls need further implementation.

Conclusion: Smoke Crypto Chat Messenger is the worlds first mobile post-quantum secure messenger, setting and implementing the standards for encrypted communication. Smoke is best suited for general users who what to emerge with learnings and cryptographical explorings to a tech-savvy user status in cryptography and security research. It serves as an important platform, demonstrating what quantum-computer-proof secure messaging has to look like in today´s quantum era and secure messaging.
