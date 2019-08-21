import asyncio
import websockets

async def echo(websocket, path):
	async for message in websocket:
		await websocket.send(message)
		print(message)
asyncio.get_event_loop().run_until_complete(
    websockets.serve(echo, 'localhost', 12345))
asyncio.get_event_loop().run_forever()