*This site is open source and under a public domain license (alternatively a creative commons license), so the content (or parts of it) can be used in (or modified for) any other project or wiki.*

# Spot-On Encryption Suite

Spot-On is an open-source Encrpytion Suite for secure Chat & E-Mail, File Transfer and also Websearch in a F2F distributed URL-Database.

Means: Spot-On is a Messaging and File-Transfer Application. With RSS you can import, read, search and distribute your feeds f2f to your friends over encrypted connections.  
Enhanced encryption processes have been invented and improved for implementation in Spot-On: such as McEliece-Messaging (Linux), Cryptographic Calling, Zero-Knowledge-Proofs, AutoCrypt via REPLEO and EPKS, Fiasco Forwarding, POPTASTIC-Messaging over E-Mail-Servers, Chipher-Text conversion tools like Rosetta Crypto Pad, Socialist-Millionaire-Security and many more.  

Spot-On utilized the Echo-Protocol for proxyfying and anonymizing the network, it provids end-to-end encryption (and therefore utilizes not a web-of-trust, which is only point-to-point encryption). Spot-On is in the groupchat and for servers compatible with Smoke Crypto Chat Messenger from F-Droid.org


# Download & Install

**Download from the Github-project-page:**

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
<li><b>Echo public-key distribution system: </b> Echo Public Key Sharing (EPKS) is a distributed public-key-sharing system. Share public-keys in a secure channel with outer users or teams and communities. </li>
<li><b>E-Mail:</b> Spot-On is an E-mail-Client (for IMAP, POP, Spot-On network e-mail).</li>
<li><b>Encryption Algorithms:</b> DSA, ECDSA, EdDSA, ElGamal, McEliece, NTRU, RSA. Spot-On is known as the first Desktop Messenger next to Smoke Mobile Crypto Chat Messenger to have utilized McEliece-Messaging in the application. Quantum computers can break the RSA, El Gamal, and elliptic curve public-key cryptosystems, as they can efficiently factor integers and extract discrete logarithms. The McEliece cryptosystem is an asymmetric encryption algorithm developed in 1978 by Robert McEliece. It was the first such scheme to use randomization in the encryption process. The algorithm is today a candidate for "post-quantum cryptography", as it is immune to attacks using Shor's algorithm ("finding the prime factors of an integer"), e.g. utilized by Quantum Computers, and – more generally – measuring coset states using Fourier sampling. Fourier sampling is a powerful technique in quantum computing that allows us to efficiently extract information from quantum circuits. It is based on the principles of the Fourier transform, a mathematical operation that decomposes a function into its frequency components. Spot-On Encryption Suite provides with McEliece Quantum Computer secure Communications and File-Transfer. </li>
<li><b>End-to-End, not Hop-to-Hop encryption: </b> While e-mail and chat often provide end-to-end encryption (as also Spot-on) file-transfer and sharing applications mostly do not support end-to-end encryption. F2F FileSharing has a good standard e.g. with a web-of-trust-architecture. But that is only hop-to-hop encryption. Within Spot-On the filesharing like torrents is real end-to-end encrypted. Spot-On supports the Magnet-URI-standard enhanced with cryptographic values for the encryption.</li>
<li><b>F2F / Friend-to-Friend Websearch based on a Distributed URL system:</b> Spot-On provides a new system of Websearch. There is alreary peer-to-peer (P2P) Websearch within just a few tools. P2P has been turn within Spot-On into F2F Wesearch, which is much more secure, while maintaining the distributed architecture. Next to this new approach it is one of the few search engines, which allow also to download the search index database of others. Do you know a websearch which is distributed? Do you know any websearch, which allows to download the search index database? Spot-On has not only updated P2P to F2F, but  offers next to a distributed approach also the download options of the full database index of this search engines. As the search results a created locally from the own database, there are no so called "queryhits" created within other nodes. The search index can be maintained within a SQLite or PostGres database - up to the expierience of the user to choose.   </li>
<li><b>Filter-Options for Websearch and URL-Database</b>: Custom URL rules can be applied as distillers - they filter domains or keywords and also p2p distributions by users.</li>
<li><b>Future-related Research and Development:</b> While the work on the client as given is completed for now, there are a lot of feature requests in the Github repositorium and as well future related ToDos in the task list of the code documentation. Currently the main focus in cooperation with the community is to set up servers for the messaging and data respective URL sharing clients, before further client improvement is conducted in the first place. Ongoing releases are updating the maintenance of the compiling process of Spot-On.</li>  
<li> <b>Individual configuration needs:</b> E.g. thread priorities are individually configurationable. Spot-On can adjust many options for individual needs of use cases of users and research models of cryptographers.</li>
<li><b>Open Source License: </b> Spot-On uses the open source BSD license, which refers to the Client and also to the integrated Server.</li>
<li><b>Socket options:</b> In addition to binding a socket to a local address or connecting it to a destination address, application programs need a method to control the socket. Application programs may also want to control the allocation of buffer space, determine if the socket allows transmission of broadcast, or control processing of out-of-band data, which is a logically independent transmission channel associated with each pair of connected stream sockets. Spot-On provides several custom socket options in this regard. </li>



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
<li><b>Web-Interface for the F2F Websearch:</b> Webbrowser like Dooble, Firefox, Lynx, etc. support for custom Web search engine by its Webinterface.</li>
<li>Windows portable.</li>
</ul>

Please visit https://github.com/textbrowser/spot-on/tree/master/branches/trunk/Documentation for more information.

![Spot-On](https://github.com/textbrowser/spot-on/blob/master/Wiki/spot-on-android.png)



# References
* Textbrowser: Documentation of Spot-On,  https://github.com/textbrowser/spot-on/tree/master/branches/trunk/Documentation

* Edwards, Scott: Manual of Spot-On Encryption Suite: [Edwards_Spot-On-Encryption-Suite_-_9783749439829.pdf](https://github.com/user-attachments/files/15521838/Edwards_Spot-On-Encryption-Suite_-_9783749439829.pdf)
