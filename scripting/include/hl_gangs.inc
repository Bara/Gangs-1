#if defined hl_gangs_include
  #endinput
#endif
#define hl_gangs_include
 
/* Gang Ranks */
enum GangRank
{
	Rank_Invalid = -1,
	Rank_Normal,
	Rank_Admin,
	Rank_Owner
}

/**
 * Outputs a formatted message to the client
 *
 * @param	client			client index
 * @return  int				gang size
 */
native void Gangs_Message(int client, const char[] format, any ...);

/**
 * Outputs a formatted message to all clients
 *
 * @param	client			client index
 * @return  int				gang size
 */
native void Gangs_MessageToAll(int client, const char[] format, any ...);

/**
 * Returns the size of a client's gang
 *
 * @param	client			client index
 * @return  int				gang size
 */
native int Gangs_GetGangSize(int client)

/**
 * Returns if a client is a member of a gang
 *
 * @param	client			client index
 * @return  bool			gang status
 */
native bool Gangs_HasGang(int client);

/**
 * Get a client's gang rank
 *
 * @param	client			client index
 * @return  GangRank		gang rank
 */
native GangRank Gangs_GetGangRank(int client);

/**
 * Get a client's gang name
 *
 * @param	client			client index
 * @return					no return
 */
native void Gangs_GetGangName(int client, char[] buffer, int maxlength);

/**
 * Returns a client's damage modifier
 *
 * @param	client			client index
 * @return  float			damage modifier
 */
native float Gangs_GetDamageModifier(client);



public SharedPlugin hl_gangs_include_shared =
{
	name = "[CS:GO] Jailbreak Gangs",
	file = "hl_gangs.smx",
#if defined REQUIRE_PLUGIN
	required = 1
#else
	required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public hl_gangs_include_shared()
{	
	MarkNativeAsOptional("Gangs_GetDamageModifier");
	MarkNativeAsOptional("Gangs_GetGangName");
	MarkNativeAsOptional("Gangs_GetGangRank");
	MarkNativeAsOptional("Gangs_HasGang");
	MarkNativeAsOptional("Gangs_GetGangSize");
	MarkNativeAsOptional("Gangs_Message");
	MarkNativeAsOptional("Gangs_MessageToAll");
}
#endif