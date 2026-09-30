import hmac, hashlib, struct, time, base64, json, urllib.request

def totp(secret: bytes, digits=10, step=30) -> str:
    counter = int(time.time()) // step
    h = hmac.new(secret, struct.pack(">Q", counter), hashlib.sha512).digest()
    off = h[-1] & 0x0F
    code = (struct.unpack(">I", h[off:off + 4])[0] & 0x7FFFFFFF) % 10 ** digits
    return str(code).zfill(digits)

email = "<YourEmail>@example.com"
password = totp((email + "HENNGECHALLENGE004").encode())
auth = base64.b64encode(f"{email}:{password}".encode()).decode()

body = json.dumps({
    "github_url": "https://gist.github.com/<ProfileName>/XXXX",
    "contact_email": email,
    "solution_language": "python",
}).encode()

req = urllib.request.Request(
    "https://api.challenge.hennge.com/challenges/backend-recursion/004",
    data=body,
    headers={"Content-Type": "application/json", "Authorization": f"Basic {auth}"},
)
print(urllib.request.urlopen(req).read().decode())