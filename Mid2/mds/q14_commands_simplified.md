# Q14 - Windows network troubleshooting commands (simplified)

Open Command Prompt: press Windows + R, type `cmd`, and press Enter. Enter each command separately. Do not type the `C:\...>` prompt. These commands match sir's Windows sheet; macOS Terminal differs. No C program is required.

All outputs below are illustrative, not measurements from your PC or the college network. Addresses, names, timings, adapter names and hop counts vary. The 192.0.2.x addresses in remote examples are fictional documentation values, not live DNS claims.

## 1. ipconfig - inspect your configuration

Input:
```text
ipconfig
```
Example output excerpt:
```text
Ethernet adapter Ethernet:
   IPv4 Address. . . . . . . . . . . : 192.168.1.10
   Subnet Mask . . . . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . . . . : 192.168.1.1
```
IPv4 is your interface's address. The mask separates network and host bits. The default gateway is the router normally used for other networks. Record the values under the active adapter. `ipconfig /all` adds details such as DNS servers and physical/MAC address.

[Microsoft reference](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/ipconfig)

## 2. ping - test whether a target responds

Input:
```text
ping 127.0.0.1
```
Example output excerpt:
```text
Reply from 127.0.0.1: bytes=32 time<1ms TTL=128
Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)
```
Ping sends ICMP Echo Requests. Replies show responsiveness; time is round-trip time, and TTL is the remaining lifetime/hop limit in the reply. Loopback tests your own IP stack, not Internet access.

Next, ping the actual gateway shown by ipconfig. For the example configuration: `ping 192.168.1.1`. `Request timed out` means no expected reply arrived in time; filtering can cause this. Optional continuous test: `ping 127.0.0.1 -t`; stop with Ctrl+C.

[Microsoft reference](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/ping)

## 3. tracert - see responding hops toward a destination

Input:
```text
tracert mgit.ac.in
```
Illustrative output excerpt:
```text
Tracing route to mgit.ac.in [192.0.2.20]
over a maximum of 30 hops:
  1     1 ms     1 ms     2 ms  192.168.1.1
  2     5 ms     6 ms     5 ms  192.0.2.1
  3    12 ms    13 ms    12 ms  192.0.2.20
Trace complete.
```
Each numbered line is a hop. Three times are round-trip measurements for three probes. Probes use increasing TTL values; intermediate ICMP replies reveal routers. A `*` means a probe timed out, not necessarily that the entire route is broken. Use Ctrl+C if you need to stop.

[Microsoft reference](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/tracert)

## 4. nslookup - check DNS resolution

Input:
```text
nslookup mgit.ac.in
```
Illustrative output:
```text
Server:  router.local
Address: 192.168.1.1

Non-authoritative answer:
Name:    mgit.ac.in
Address: 192.0.2.20
```
The first Server/Address pair identifies the DNS server answering you. The Name/Address pair is the requested domain's result. Non-authoritative means the answer comes from a resolver rather than directly from that domain's authoritative server; it is not an error. A timeout means the DNS query was not answered in time. The actual answer may contain multiple IPv4/IPv6 addresses.

[Microsoft reference](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/nslookup)

## 5. arp -a - inspect local IPv4-to-MAC mappings

Input:
```text
arp -a
```
Illustrative output excerpt:
```text
Interface: 192.168.1.10 --- 0x5
  Internet Address      Physical Address      Type
  192.168.1.1           02-11-22-33-44-55     dynamic
```
Internet Address is the neighbour's IPv4 address; Physical Address is its MAC address. Dynamic means the entry was learned automatically. The Interface line identifies your local adapter. ARP shows cached mappings, not a scan of every device. If the gateway entry is absent, ping your actual gateway and inspect the cache again.

[Microsoft reference](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/arp)

## Exam execution order

1. Run `ipconfig`; note your IPv4 address, mask and gateway.
2. Run `ping 127.0.0.1`; then ping the actual gateway.
3. Run `tracert mgit.ac.in`; identify hop numbers and times.
4. Run `nslookup mgit.ac.in`; distinguish DNS-server address from domain address.
5. Run `arp -a`; identify an IPv4-to-MAC mapping.

Remember: ipconfig = my settings; ping = does it respond; tracert = which hops; nslookup = name lookup; arp = local IP-to-MAC cache.
